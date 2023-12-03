#include "Jeu.h"
#include "Arme.h"
#include "Armure.h"
#include "Narrateur.h"
#include "Joueur.h"
#include "Catalogue.h"
#include <algorithm>

#include <fstream>
#include <chrono>
#include <thread>
#include <iostream>
#include <typeinfo>
#include <random>

using namespace std;

Jeu::Jeu()
{
    gameIsRunning = true;
    vectorObjet = vector<Objet *>();
    vectorPersonnage = vector<Personnage *>();
    listText = list<string>();
    vectorToDo = vector<OperationToDo>();
    narrateur = Narrateur();
    joueurHumain = JoueurHumain();
    joueurHumain.setNarrateur(&narrateur);
    joueurHumain.joueurTag = TAG_PLAYER;
    joueurIA = JoueurMonstre();
    joueurIA.setNarrateur(&narrateur);
    joueurIA.joueurTag = TAG_MONSTRE;
    catalogue = Catalogue(this);
    srand(time(NULL));
}

Jeu::~Jeu()
{
}

void Jeu::start()
{
    string text;
    vector<int> *vector_path;
    int pathToGo;

    //Creation de personnage
    creationDePersonnage();

    //Le jeu en tant que tel commence 
    goToPath(0);
    while (gameIsRunning)
    {
        // Do an operation
        OperationToDo operation_to_do = vectorToDo.front();
        vectorToDo.erase(vectorToDo.begin());

        switch (operation_to_do.operation)
        {
        case TEXT:
            text = *((string *)operation_to_do.pointer_1);
            narrateur.printScreen(text);
            listText.remove(text);
            break;

        case COMBAT:
            joueurIA.addPersonnage((Personnage *)operation_to_do.pointer_1);
            joueurIA.joueurTag = TAG_MONSTRE;
            startCombat2Joueur(&joueurHumain, &joueurIA);
            break;

        case ARME:
            prendreArme(joueurHumain.vectorPersonnage[0], ((Arme *)operation_to_do.pointer_1));
            break;

        case ARMURE:
            prendreArmure(joueurHumain.vectorPersonnage[0], ((Armure *)operation_to_do.pointer_1));
            break;

        case GO:
            lose();
            break;

        case PATH:
            vector_path = (vector<int> *)operation_to_do.pointer_1;
            pathToGo = -1;
            if (vector_path->size() == 2)
            {
                if (vector_path->at(0) == vector_path->at(1))
                {
                    pathToGo = vector_path->at(0);
                }
            }
            if (pathToGo == -1)
            {
                pathToGo = vector_path->at(joueurHumain.deciderPath(vector_path->size()));
            }

            delete vector_path;
            if (pathToGo >= 0)
            {
                goToPath(pathToGo);
            }
            else
            {
                throw logic_error("Error in the path algo, pathToGo is " + to_string(pathToGo));
            }
            break;

        case VICTOIRE:
            win();
            break;

        default:
            break;
        }
    }
}

void Jeu::goToPath(int path)
{
    // flush all previous operation to do
    vectorToDo.clear();
    readText(path);
}

void Jeu::readText(int i)
{
    // read text into buffer
    string path = "text/" + to_string(i) + ".txt";
    ifstream myfile(path);
    string line;
    vector<string> myLines;
    while (getline(myfile, line))
    {
        myLines.push_back(line);
    }

    // parse text into a comportement tree
    string cumulative_string = "";
    bool new_text_operation = true;
    OperationToDo operation;
    for (auto it = myLines.begin(); it != myLines.end(); ++it)
    {
        string line_ = *it;
        if (line_ == "*COMBAT*")
        {
            operation.operation = COMBAT;
            operation.pointer_1 = catalogue.basic(*(it + 1), stoi(*(it + 2)), stoi(*(it + 3)));
            vectorToDo.push_back(operation);
            it = it + 3;
            new_text_operation = true;
        }
        else if (line_ == "*ARME*")
        {
            operation.operation = ARME;
            operation.pointer_1 = catalogue.armeBasic(*(it + 1), stoi(*(it + 2)));
            vectorToDo.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*ARMURE*")
        {
            operation.operation = ARMURE;
            operation.pointer_1 = catalogue.armureBasic(*(it + 1), stoi(*(it + 2)));
            vectorToDo.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*GO*")
        {
            operation.operation = GO;
            operation.pointer_1 = nullptr;
            vectorToDo.push_back(operation);
            new_text_operation = true;
        }
        else if (line_ == "*PATH*")
        {
            vector<int> *vector_path = new vector<int>;
            (*vector_path).push_back(stoi(*(it + 1)));
            (*vector_path).push_back(stoi(*(it + 2)));

            operation.operation = PATH;
            operation.pointer_1 = vector_path;
            vectorToDo.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*VICTOIRE*")
        {
            operation.operation = VICTOIRE;
            operation.pointer_1 = nullptr;
            vectorToDo.push_back(operation);
            new_text_operation = true;
        }
        else
        {
            // cout << endl << "debug print" << endl;
            // cout << line_ << endl;
            // cout << "debug print end" << endl << endl;
            if (new_text_operation)
            {
                listText.push_back(line_ + "\n");
                operation.operation = TEXT;
                operation.pointer_1 = &listText.back();
                vectorToDo.push_back(operation);
                new_text_operation = false;
            }
            else
            {
                listText.back() = listText.back() + line_ + "\n";
            }
        }
    }

    // start going through the tree ?
}

void Jeu::creationDePersonnage()
{
    // choix de classe
    narrateur.printScreen("Choisis ta classe : Guerrier = 1, Rodeur = 2, Mage = 3.");
    int choixClasse = joueurHumain.deciderClasse(3);
    Personnage *personnageJoueur;
    switch (choixClasse)
    {
    case 1:
        personnageJoueur = catalogue.guerrier();
        break;
    case 2:
        personnageJoueur = catalogue.rodeur();
        break;
    case 3:
        personnageJoueur = catalogue.mage();
        break;

    default:
        throw invalid_argument("out of bound choice");
    }
    joueurHumain.addPersonnage(personnageJoueur);

    // choix de nom
    narrateur.printScreen("Choisis ton nom :");
    string choixNom = joueurHumain.deciderNom();
    personnageJoueur->set_nom(choixNom);
    // choix d'atribut ?
    // classe en plus ?
    // choix de race ?
}

void Jeu::killPersonnage(Personnage *personnage)
{
    joueurHumain.removePersonnage(personnage);
    joueurIA.removePersonnage(personnage);
    std::vector<Personnage *>::iterator position = std::find(vectorPersonnage.begin(), vectorPersonnage.end(), personnage);
    if (position != vectorPersonnage.end())
    { // == vectorPersonnage.end() means the element was not found
        vectorPersonnage.erase(position);
    }
    delete personnage;
}

void Jeu::killPersonnageFromJoueur(Joueur *joueur)
{
    while (joueur->vectorPersonnage.size() > 0)
    {
        killPersonnage(joueur->vectorPersonnage[0]);
    }
}

void Jeu::prendreArme(Personnage *joueur, Arme *objet)
{
    if(narrateur.prendreArme(joueur, objet)){
        joueur->add_equip_arme(objet);
    }
}

void Jeu::prendreArmure(Personnage *joueur, Armure *objet)
{ 
    if(narrateur.prendreArmure(joueur, objet)){
        joueur->add_equip_armure(objet);
    }
}

void Jeu::prendreConsommable(Personnage *joueur, Consommable *objet)
{
    if(narrateur.prendreConsommable(joueur, objet)){
        joueur->add_consommable(objet);
    }
}

void Jeu::lose()
{
    narrateur.lose();
    system("pause");
    gameIsRunning = false;
}

void Jeu::win()
{
    narrateur.win();
    system("pause");
    gameIsRunning = false;
}

void Jeu::startCombat2Joueur(Joueur *joueur1, Joueur *joueur2)
{
    // Initialisation
    Joueur *deadJoueur;
    int turn = 0;
    // each iteration is a turn from a joueur
    while (joueur1->isAlive() && joueur2->isAlive())
    {
        if (turn % 2 == 0) {
            joueur1->deciderCombat2Joueur(joueur2);
        }
        else if (turn % 2 == 1) {
            joueur2->deciderCombat2Joueur(joueur1);
        }
        turn++;
    }

    // Check who is dead
    if (!joueur1->isAlive())
    {
        deadJoueur = joueur1;
    }
    else if (!joueur2->isAlive())
    {
        deadJoueur = joueur2;
    }
    else
    {
        throw runtime_error("The combat has ended but nobody is dead ?");
    }

    // Do something with the dead joueur
    if (deadJoueur->joueurTag == TAG_PLAYER)
    {
        this->lose();
    }
    else
    {
        killPersonnageFromJoueur(deadJoueur);
    }
}

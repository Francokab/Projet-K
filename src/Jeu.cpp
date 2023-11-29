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

using namespace std;

Jeu::Jeu()
{
    gameState = 0;  //which file are we on
    gameIsRunning = true;
    vectorObjet = vector<Objet*>();
    vectorPersonnage = vector<Personnage*>();
    listText = list<string>();
    vectorToDo = vector<OperationToDo>();
    narrateur = Narrateur();
    joueurHumain = JoueurHumain();
    joueurIA =  JoueurMonstre();
    catalogue = Catalogue();
}

Jeu::~Jeu()
{

}

void Jeu::start() {
    string text;
    vector<int>* vector_path;
    int pathToGo;
    int debug;

    // Initialisation de truc

    // creation de personnage
    creationDePersonnage();

    // the game start
    goToPath(0);
    while (gameIsRunning) {
        // Do an operation
        OperationToDo operation_to_do = vectorToDo.front();
        vectorToDo.erase(vectorToDo.begin());

        // Debug
        // cout << "vectorToDo :\n"; 
        // for (OperationToDo op: vectorToDo) {
        //     cout << op.operation << " " << op.pointer_1 << "\n";
        // }
        // cout << "current operation : " << operation_to_do.operation << " " << operation_to_do.pointer_1 << "\n";
        // cin >> debug;
        // cout << "\n";

        // switch
        switch (operation_to_do.operation)
        {
        case TEXT:
            text = *((string*)operation_to_do.pointer_1);
            narrateur.printScreen(text);
            break;

        case COMBAT:
            joueurIA.addPersonnage((Personnage*)operation_to_do.pointer_1);
            startCombat({&joueurHumain, &joueurIA});
            break;

        case ARME:
            prendreObjet(joueurHumain.vectorPersonnage[0], ((Objet*)operation_to_do.pointer_1));
            break;

        case ARMURE:
            prendreObjet(joueurHumain.vectorPersonnage[0], ((Objet*)operation_to_do.pointer_1));
            break;

        case GO:
            lose();
            break;

        case PATH:
            vector_path = (vector<int>*)operation_to_do.pointer_1;
            pathToGo = -1;
            if (vector_path->size() == 2) {
                if (vector_path->at(0) == vector_path->at(1)) {
                    pathToGo = vector_path->at(0);
                }
            }
            if (pathToGo == -1) {
            pathToGo = vector_path->at(narrateur.choixJoueurInt(vector_path->size()) - 1);
            }

            delete vector_path;
            if (pathToGo >= 0) {
                goToPath(pathToGo);
            } else { throw logic_error("Error in the path algo, pathToGo is " + to_string(pathToGo));}
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

void Jeu::readText(int i) {
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
    for (auto it = myLines.begin(); it != myLines.end(); ++it) {
        string line_ = *it; 
        if (line_ == "*COMBAT*") {
            vectorPersonnage.push_back(new Personnage(*(it+1), stoi(*(it+2)), stoi(*(it+3))));
            operation.operation = COMBAT;
            operation.pointer_1 = vectorPersonnage.back();
            vectorToDo.push_back(operation);
            it = it + 3;
            new_text_operation = true;
        }
        else if (line_ == "*ARME*") {
            vectorObjet.push_back(new Arme(*(it+1), stoi(*(it+2))));
            operation.operation = ARME;
            operation.pointer_1 = vectorObjet.back();
            vectorToDo.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*ARMURE*") {
            vectorObjet.push_back(new Armure(*(it+1), stoi(*(it+2))));
            operation.operation = ARMURE;
            operation.pointer_1 = vectorObjet.back();
            vectorToDo.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*GO*") {
            operation.operation = GO;
            operation.pointer_1 = nullptr;
            vectorToDo.push_back(operation);
            new_text_operation = true;
        }
        else if (line_ == "*PATH*") {
            vector<int>* vector_path = new vector<int>;
            (*vector_path).push_back(stoi(*(it+1)));
            (*vector_path).push_back(stoi(*(it+2)));

            operation.operation = PATH;
            operation.pointer_1 = vector_path;
            vectorToDo.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*VICTOIRE*") {
            operation.operation = VICTOIRE;
            operation.pointer_1 = nullptr;
            vectorToDo.push_back(operation);
            new_text_operation = true;
        }
        else {
            if (new_text_operation) {
                listText.push_back(line_);
                operation.operation = TEXT;
                operation.pointer_1 = &listText.back();
                vectorToDo.push_back(operation);
                new_text_operation = false;
            }
            else {
                listText.back() = listText.back() + line_;
            }
        }
    }

    // start going through the tree ?
}

void Jeu::creationDePersonnage()
{
    // choix de classe
    int choixClasse = narrateur.choixJoueurInt("Choisis ta classe : Guerrier = 1, Rodeur = 2, Mage = 3.");
    Personnage* personnageJoueur;
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
    vectorPersonnage.push_back(personnageJoueur);
    joueurHumain.addPersonnage(personnageJoueur);
    // choix de nom
    string choixNom = narrateur.choixJoueurString("Choisis ton nom :");
    personnageJoueur->set_nom(choixNom);
    // choix d'atribut ?
    // classe en plus ?
    // choix de race ?
}

void Jeu::killPersonnage(Personnage *personnage)
{
    joueurHumain.removePersonnage(personnage);
    joueurIA.removePersonnage(personnage);
    std::vector<Personnage*>::iterator position = std::find(vectorPersonnage.begin(), vectorPersonnage.end(), personnage);
    if (position != vectorPersonnage.end()) {// == vectorPersonnage.end() means the element was not found
        vectorPersonnage.erase(position);
    }
    delete personnage;
}

void Jeu::prendreObjet(Personnage* joueur, Objet* objet) {
    if (typeid(*objet) == typeid(Arme)) {
        joueur->add_arme((Arme *)objet);
    }
    else if (typeid(*objet) == typeid(Armure)) {
        joueur->add_armure((Armure *)objet);
    }
    else if (typeid(*objet) == typeid(Consommable)) {
        joueur->add_consommable((Consommable *)objet);
    }
    else {
        throw invalid_argument("objet is not arme, armure or consommable");
    }
    narrateur.prendreObjet(joueur, objet);
}

void Jeu::lose(){
    narrateur.lose();
    system("pause");
    gameIsRunning = false;
}

void Jeu::win(){
    narrateur.win();
    system("pause");
    gameIsRunning = false;
}

void Jeu::startCombat(vector<Joueur*> joueurEnCombat){

    bool j1_vivant = true;
    Joueur* j1 = joueurEnCombat[0];
    Personnage *p1 = j1->vectorPersonnage[0];
    vector<Personnage *> ennemis1 = {p1};

    bool j2_vivant = true;
    Joueur* j2 = joueurEnCombat[0];
    Personnage *p2 = j2->vectorPersonnage[0];
    vector<Personnage *> ennemis2 = {p2};

    while(j1_vivant && j2_vivant){
        j1->deciderAction(ennemis2, 1);
        if(p2->get_pv() <= 0){
            j2_vivant = false;
        }
        j2->deciderAction(ennemis1, 1);
        if(p1->get_pv() <= 0) {
            j1_vivant = false;
        }
        cout << p1->get_nom() << " a " << p1->get_pv() << " point de vie !" << endl;
        cout << p2->get_nom() << " a " << p2->get_pv() << " point de vie !" << endl;
    }

    if(!j2_vivant){
        //C'est le monstre à combattre
        cout << "Le " << p2->get_nom() << " est mort !" << endl;
        killPersonnage(p2);
    }
    else if(!j1_vivant){
        this->lose();
    }
    else {
        cout << "Error at the end of the combat ??" << endl;
        this->lose();
    }

}
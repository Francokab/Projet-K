#include "Jeu.h"
#include "Monstre.h"
#include "Joueurs.h"
#include "Arme.h"
#include "Armure.h"
#include "Civil.h"
#include "Narrateur.h"

#include <fstream>
#include <chrono>
#include <thread>
#include <iostream>
#include <typeinfo>

using namespace std;

Jeu::Jeu()
{
    gameState = 0;
    gameIsRunning = true;
    vector<Objet*> vectorObjet = vector<Objet*>();
    vector<Personnage*> vectorPersonnage = vector<Personnage*>();
    list<string> listText = list<string>();
    vector<OperationToDo> vectorToDo = vector<OperationToDo>();
    Narrateur narrateur = Narrateur();

}

Jeu::~Jeu()
{

}

void Jeu::start() {
    string text;
    vector<int>* vector_path;

    // Initialisation de truc

    // creation de personnage
    creationDePersonnage();

    // the game start
    while (gameIsRunning) {
        // Do an operation
        OperationToDo operation_to_do = vectorToDo.front();

        // switch
        switch (operation_to_do.operation)
        {
        case TEXT:
            text = *((string*)operation_to_do.pointer_1);
            narrateur.printScreen(text);
            break;

        case COMBAT:
            startCombat({&joueur, ((Personnage*)operation_to_do.pointer_1)});
            break;

        case ARME:
            prendreObjet(&joueur, ((Objet*)operation_to_do.pointer_1));
            break;

        case ARMURE:
            prendreObjet(&joueur, ((Objet*)operation_to_do.pointer_1));
            break;

        case GO:
            lose();
            break;

        case PATH:
            vector_path = (vector<int>*)operation_to_do.pointer_1;
            if (vector_path->size() == 2) {
                if (vector_path[0] == vector_path[1]) {
                    //go to path 0 and break
                }
            }
            // demand input (with max vector_path.size()) and then go there and break

            delete vector_path;
            break;

        case VICTOIRE:
            win();
            break;
        
        default:
            break;
        }

    }
}

void Jeu::readText(int i) {
    // flush all previous operation to do
    vectorToDo.clear();

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
            vectorPersonnage.push_back(new Monstre(*(it+1), stoi(*(it+2)), stoi(*(it+3))));
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
    
    // choix de nom
    // choix d'atribut ?
    // classe en plus ?
    // choix de race ?
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

void Jeu::startCombat(vector<Personnage*> personnageEnCombat){

    bool personnages_vivant = true;
    Personnage *p1 = personnageEnCombat[0];
    vector<Personnage *> ennemis1 = {p1};

    Personnage *p2 = personnageEnCombat[1];
    vector<Personnage *> ennemis2 = {p2};

    while(personnages_vivant){
        p1->deciderAction(ennemis2, 1);
        if(p2->get_pv() <= 0){
            personnages_vivant = false;
        }
        p2->deciderAction(ennemis1, 1);
        if(p1->get_pv() <= 0) {
            personnages_vivant = false;
        }
        cout << p1->get_nom() << " a " << p1->get_pv() << " point de vie !" << endl;
        cout << p2->get_nom() << " a " << p2->get_pv() << " point de vie !" << endl;
    }

    for(Personnage *p : personnageEnCombat){

        if(dynamic_cast<Monstre *>(p) != nullptr){
            //C'est le monstre à combattre
            if(p->get_pv() <= 0){
                cout << "Le " << p->get_nom() << " est mort !" << endl;
            }


        } else if(dynamic_cast<Civil *> (p) != nullptr){
            //C'est un civil

        } else {
            //C'est un joueur
            if(p->get_pv() <= 0){
                this->lose();
            }
        }
    }


}
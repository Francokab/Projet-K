#include "Jeu.h"
#include "monstre.h"
#include "Arme.h"
#include "Armure.h"
#include <fstream>

using namespace std;

Jeu::Jeu()
{
    game_state = 0;
    game_is_running = true;
    //list_objet = list<Objet>();
    //list_personnage = list<Personnage>();
    // joueur = Joueurs();

}

Jeu::~Jeu()
{

}

void Jeu::start() {
    // Initialisation de truc

    //creation de personnage

    while (game_is_running) {
        // Do an operation
        OperationToDo operation_to_do = vector_to_do.front();

        // switch
    }
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
            vector_personnage.push_back(new Monstre(*(it+1), stoi(*(it+2)), stoi(*(it+3))));
            operation.operation = COMBAT;
            operation.pointer_1 = vector_personnage.back();
            vector_to_do.push_back(operation);
            it = it + 3;
            new_text_operation = true;
        }
        else if (line_ == "*ARME*") {
            vector_objet.push_back(new Arme(*(it+1), stoi(*(it+2))));
            operation.operation = ARME;
            operation.pointer_1 = vector_objet.back();
            vector_to_do.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*ARMURE*") {
            vector_objet.push_back(new Armure(*(it+1), stoi(*(it+2))));
            operation.operation = ARMURE;
            operation.pointer_1 = vector_objet.back();
            vector_to_do.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*GO*") {
            operation.operation = GO;
            operation.pointer_1 = nullptr;
            vector_to_do.push_back(operation);
            new_text_operation = true;
        }
        else if (line_ == "*PATH*") {
            vector<int>* vector_path = new vector<int>;
            (*vector_path).push_back(stoi(*(it+1)));
            (*vector_path).push_back(stoi(*(it+2)));

            operation.operation = PATH;
            operation.pointer_1 = vector_path;
            vector_to_do.push_back(operation);
            it = it + 2;
            new_text_operation = true;
        }
        else if (line_ == "*VICTOIRE*") {
            operation.operation = VICTOIRE;
            operation.pointer_1 = nullptr;
            vector_to_do.push_back(operation);
            new_text_operation = true;
        }
        else {
            if (new_text_operation) {
                list_text.push_back(line_);
                operation.operation = TEXT;
                operation.pointer_1 = &list_text.back();
                vector_to_do.push_back(operation);
                new_text_operation = false;
            }
            else {
                list_text.back() = list_text.back() + line_;
            }
        }
    }

    // start going through the tree ?
}

void Jeu::lose(){
    cout << "Tout le courage du monde ne suffit parfois pas..." << endl;
    cout << "Vous êtes mort !!!!!" << endl;
    cout << "Tin Tin Tin !" << endl;
    cout << "\n" << endl;
    cout << "Appuyer sur une touche pour quitter le jeu." << endl;
}
#include "Jeu.h"
#include <fstream>

using namespace std;

Jeu::Jeu()
{
    game_state = 0;
    vector_objet = vector<Objet>();
    vector_personnage = vector<Personnage>();
    // joueur = Joueurs();

}

Jeu::~Jeu()
{

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


    // start going through the tree ?
}
#include "Jeu.h"

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
    std::cout << i << "\n";
    // read text into buffer

    // parse text into a comportement tree

    // start going through the tree ?
}
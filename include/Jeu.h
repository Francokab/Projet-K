#ifndef JEU_H
#define JEU_H

#pragma once

#include "AllFiles.h"
#include <vector>

class Jeu
{
public:
    Jeu();
    ~Jeu();

    int game_state;  //which file are we on
    vector<Objet> vector_objet;
    vector<Personnage> vector_personnage;
    Joueurs joueur;

    void start();
    void readText(int i);


private:

};

#endif
#ifndef JEU_H
#define JEU_H

#pragma once

#include "Objet.h"
#include "personnage.h"
#include <vector>
#include <list>

// Define an enum
enum OPERATION {
    NONE,
    TEXT,
    COMBAT,
    ARME,
    ARMURE,
    GO,
    PATH, //Must Delete the pointer after use
    VICTOIRE
};

// Define a struct with an enum and a pointer
struct OperationToDo {
    OPERATION operation;
    void* pointer_1;
};

class Jeu
{
public:
    Jeu();
    ~Jeu();

    int game_state;  //which file are we on
    vector<Objet*> vector_objet;
    vector<Personnage*> vector_personnage;
    list<string> list_text;
    vector<OperationToDo> vector_to_do;

    // Joueurs joueur;

    void start();
    void startCombat(vector<Personnage*> personnage_en_combat);
    void prendreObjet(Personnage joueur, Objet objet);
    void lose();
    void win();
    void readText(int i);


private:

};

#endif
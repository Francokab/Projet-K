#ifndef JEU_H
#define JEU_H

#pragma once

#include "Objet.h"
#include "Personnage.h"
#include "Narrateur.h"
#include "Joueur.h"
#include "Catalogue.h"
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

    int gameState;  //which file are we on
    bool gameIsRunning;
    vector<Objet*> vectorObjet;
    vector<Personnage*> vectorPersonnage;
    list<string> listText;
    vector<OperationToDo> vectorToDo;
    Narrateur narrateur;
    JoueurHumain joueurHumain;
    JoueurMonstre joueurIA;
    Catalogue catalogue;
    


    void start();
    void startCombat(vector<Joueur*> joueurEnCombat);
    void prendreObjet(Personnage* joueur, Objet* objet);
    void lose();
    void win();
    void readText(int i);
    void creationDePersonnage();


private:

};

#endif
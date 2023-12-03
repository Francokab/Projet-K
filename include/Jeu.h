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
enum OPERATION
{
    NONE,
    TEXT,
    COMBAT,
    ARME,
    ARMURE,
    GO,
    PATH, // Must Delete the pointer after use
    VICTOIRE
};

// Define a struct with an enum and a pointer
struct OperationToDo
{
    OPERATION operation;
    void *pointer_1;
};

class Jeu
{
public:
    Jeu();
    ~Jeu();

    bool gameIsRunning;
    vector<Objet *> vectorObjet;
    vector<Personnage *> vectorPersonnage;
    list<string> listText;
    vector<OperationToDo> vectorToDo;
    Narrateur narrateur;
    JoueurHumain joueurHumain;
    JoueurMonstre joueurIA;
    Catalogue catalogue;

    void start();
    void goToPath(int path);
    //void startCombat(vector<Joueur *> joueurEnCombat); // Deprecated
    void startCombat2Joueur(Joueur *joueur1, Joueur *joueur2);
    void prendreArme(Personnage *joueur, Arme *objet);
    void prendreArmure(Personnage *joueur, Armure *objet);
    void prendreConsommable(Personnage *joueur, Consommable *objet);
    void lose();
    void win();
    void readText(int i);
    void creationDePersonnage();
    void killPersonnage(Personnage *personnage);   // remove Personnage from everything and delete it
    void killPersonnageFromJoueur(Joueur *joueur); // remove all Personnage from joueur from everything and delete it

private:
};

#endif
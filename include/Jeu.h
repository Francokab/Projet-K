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

    void start();            // main loop here, does one operation per iteration
    void goToPath(int path); // clear vectorToDo and readText
    // void startCombat(vector<Joueur *> joueurEnCombat); // Deprecated
    void startCombat2Joueur(Joueur *joueur1, Joueur *joueur2); // start a combat between two joueur against each other
    void prendreArme(Personnage *joueur, Arme *objet);
    void prendreArmure(Personnage *joueur, Armure *objet);
    void prendreConsommable(Personnage *joueur, Consommable *objet);
    void lose();
    void win();
    void readText(int i); // parse a text file and add the operation to do in vectorToDo
    void creationDePersonnage();
    void killPersonnage(Personnage *personnage);           // remove Personnage and its object from everything and delete it
    void killObject(Objet *objet);                         // remove objet from jeu and delete it
    void killObjectFromPersonnage(Personnage *personnage); // remove all object from personnage and delete them
    void killPersonnageFromJoueur(Joueur *joueur);         // remove all Personnage from joueur from everything and delete it

private:
};

#endif
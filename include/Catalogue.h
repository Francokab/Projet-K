#ifndef CATALOGUE_H
#define CATALOGUE_H

#pragma once

#include "Personnage.h"
#include "Objet.h"
class Jeu; // Forward Declaration because of circular dependancy

// list of constructer of typical object, automaticaly add them to jeu's vectors
class Catalogue
{
public:
    Catalogue();
    Catalogue(Jeu *jeu);
    ~Catalogue();

    Jeu *jeu;

    Personnage *basic();                              // for monster coming from text files
    Personnage *basic(string nom, int pv, int force); // for monster coming from text files
    Personnage *guerrier();
    Personnage *rodeur();
    Personnage *mage();
    Personnage *artificier();

    Arme *armeBasic(std::string nom_, int attaque_); // for arme coming from text files
    Arme *poing();
    Arme *epee();
    Arme *dagues();
    Arme *baton();
    Armure *armureBasic(std::string nom_, int defense_); // for armure coming from text files
    Armure *peau();
    Armure *cuirasse();
    Armure *cuir();
    Armure *tissus();

    Consommable *bombe();
    Consommable *potionDeVie();

private:
};

#endif
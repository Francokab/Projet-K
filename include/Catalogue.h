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
    Catalogue(Jeu* jeu);
    ~Catalogue();

    Jeu *jeu;

    Personnage *basic();
    Personnage *basic(string nom, int pv, int force);
    Personnage *guerrier();
    Personnage *rodeur();
    Personnage *mage();

    Arme *poing();
    Arme *epee();
    Arme *dagues();
    Arme *baton();
    Armure *peau();
    Armure *cuirasse();
    Armure *cuir();
    Armure *tissus();

private:
};

#endif
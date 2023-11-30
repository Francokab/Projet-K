#ifndef CATALOGUE_H
#define CATALOGUE_H

#pragma once

#include "Personnage.h"
#include "Objet.h"
#include "Jeu.h"

// list of constructer of typical object, automaticaly add them to jeu's vectors
class Catalogue
{
public:
    Catalogue(Jeu *jeu);
    ~Catalogue();

    Jeu *jeu;

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
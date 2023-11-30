#ifndef CATALOGUE_H
#define CATALOGUE_H

#pragma once

#include "Personnage.h"
#include "Objet.h"

// list of constructer of typical object
class Catalogue
{
public:
    Catalogue();
    ~Catalogue();

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
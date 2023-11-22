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

    Personnage guerrier();
    Personnage rodeur();
    Personnage mage();

    Objet epee();
    Objet dagues();
    Objet baton();
    Objet cuirasse();
    Objet cuir();
    Objet tissus();

    

private:

};

#endif
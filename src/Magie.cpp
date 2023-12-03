#include "Magie.h"
#include <iostream>

Magie::Magie() : manaPrix(0), nbrUtilisationMax(5)
{
}

Magie::Magie(int manaPrix_, int nbrUtilisationMax_) : manaPrix(manaPrix_), nbrUtilisationMax(nbrUtilisationMax_)
{
}

Magie::Magie(std::string nom_, int manaPrix_, int nbrUtilisationMax_)
{
    nom = nom_;
    // prix = 0;
    // poids = 0;
    manaPrix = manaPrix_;
    nbrUtilisationMax = nbrUtilisationMax_;
}

/* Magie::Magie(std::string nom_, int prix_, int poids_, int manaPrix_, int nbrUtilisationMax_)
{
    nom = nom_;
    prix = prix_;
    poids = poids_;
    manaPrix = manaPrix_;
    nbrUtilisationMax = nbrUtilisationMax_;
} */

Magie::~Magie()
{
}

void BouleDeFeu::effet()
{
    std::cout << "Boule de feu \n";
}
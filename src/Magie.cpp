#include "Magie.h"
#include <iostream>

Magie::Magie(): manaPrix(0), nbrUtilisationMax(5)
{

}

Magie::~Magie()
{

}

void BouleDeFeu::effet() {
    std::cout << "Boule de feu \n";
}
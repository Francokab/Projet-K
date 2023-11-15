#include "Arme.h"

Arme::Arme() : attaque(0)
{

}

Arme::Arme(int attaque_) : attaque(attaque_)
{

}

Arme::Arme(std::string nom_, int prix_, int poids_, int attaque_) {
    nom = nom_;
    prix = prix_;
    poids = poids_;
    attaque = attaque_;
}

Arme::~Arme()
{

}
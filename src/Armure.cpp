#include "Armure.h"

Armure::Armure(): defense(0)
{

}

Armure::Armure(int defense_) : defense(defense_)
{

}

Armure::Armure(std::string nom_, int prix_, int poids_, int defense_) {
    nom = nom_;
    prix = prix_;
    poids = poids_;
    defense = defense_;
}

Armure::~Armure()
{

}
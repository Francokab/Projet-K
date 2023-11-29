#include "Objet.h"

Objet::Objet() : nom(""), prix(0), poids(0)
{
}

Objet::Objet(std::string nom_, int prix_, int poids_) : nom(nom_), prix(prix_), poids(poids_)
{
}

Objet::~Objet()
{
}
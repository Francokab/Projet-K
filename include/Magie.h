#ifndef MAGIE_H
#define MAGIE_H

#pragma once

#include "Objet.h"

using namespace std;

class Joueur;
class Personnage;

class Magie : public Objet
{
public:
    Magie();
    // Magie(std::string nom_, int prix_, int poids_, int manaPrix_, int nbrUtilisationMax_);
    Magie(int manaPrix_, int nbrUtilisationMax_);
    Magie(std::string nom_, int manaPrix_, int nbrUtilisationMax_);
    ~Magie();

    int manaPrix;
    int nbrUtilisationMax;

    virtual void effet(Joueur *joueurEnnemi, Personnage *personnageActuel) = 0;

private:
};

class BouleDeFeu : public Magie
{
public:
    BouleDeFeu(string nom_, int manaPrix_, int nbrUtilisationMax_);
    void effet(Joueur *joueurEnnemi, Personnage *personnageActuel);
};

#endif
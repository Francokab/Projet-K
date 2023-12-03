#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H

#pragma once

#include "objet.h"
#include "string"


using namespace std;

class Joueur;
class Personnage;

class Consommable : public Objet
{
public:
    Consommable();
    Consommable(string nom, int prix);
    ~Consommable();

    string get_nom(){return nom;}

    virtual void effet(Joueur *joueurEnnemi, Personnage *personnageActuel) = 0;

protected:
    string nom;
    int prix;
};

class PotionDeVie : public Consommable
{
public:
    PotionDeVie(string nom, int prix);
    void effet(Joueur *joueurEnnemi, Personnage *personnageActuel);
};

class Bombe : public Consommable
{
public:
    Bombe(string nom, int prix);
    void effet(Joueur *joueurEnnemi, Personnage *personnageActuel);
};

#endif
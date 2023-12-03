#ifndef MAGIE_H
#define MAGIE_H

#pragma once

#include "Objet.h"

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

    virtual void effet() = 0;

private:
};

class BouleDeFeu : public Magie
{
public:
    void effet();
};

#endif
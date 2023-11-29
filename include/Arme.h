#ifndef ARME_H
#define ARME_H

#pragma once

#include "Objet.h"

class Arme : public Objet
{
public:
    Arme();
    Arme(std::string nom_, int prix_, int poids_, int attaque_);
    Arme(int attaque_);
    Arme(std::string nom_, int attaque_);
    ~Arme();

    int attaque;

private:
};

#endif
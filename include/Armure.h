#ifndef ARMURE_H
#define ARMURE_H

#pragma once

#include "Objet.h"

class Armure : public Objet
{
public:
    Armure();
    // Armure(std::string nom_, int prix_, int poids_, int defense_);
    Armure(std::string nom_, int defense_);
    Armure(int defense_);
    ~Armure();

    int defense;

private:
};

#endif
#ifndef CONSOMMABLE_H
#define CONSOMMABLE_H

#pragma once

#include "Objet.h"

class Consommable : public Objet
{
public:
    Consommable();
    ~Consommable();

    virtual void effet() = 0;

private:

};

class PotionDeVie : public Consommable {public: void effet();};

#endif
#ifndef NARRATEUR_H
#define NARRATEUR_H

#pragma once

#include <iostream>
#include "Personnage.h"
#include "Objet.h"

using namespace std;

class Narrateur
{
public:
    Narrateur();
    ~Narrateur();

    void choixJoueur();
    void printScreen();
    void printScreen(string text);
    void prendreObjet(Personnage* joueur, Objet* objet);
    void win();
    void lose();

private:

};

#endif
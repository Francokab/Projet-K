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

    int choixJoueurInt();
    int choixJoueurInt(string text_to_print);
    string choixJoueurString();
    string choixJoueurString(string text_to_print);
    void printScreen();
    void printScreen(string text);
    void prendreObjet(Personnage* joueur, Objet* objet);
    void win();
    void lose();

private:

};

#endif
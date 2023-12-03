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
    int choixJoueurInt(int max);          // max exclusif
    int choixJoueurInt(int min, int max); // min inclusif
    int choixJoueurInt(string text_to_print, int max);
    int choixJoueurInt(string text_to_print, int min, int max);
    int prendreArme(Personnage *joueur, Arme *arme);
    int prendreArmure(Personnage *joueur, Armure *armure);
    int prendreConsommable(Personnage *joueur, Consommable *consommable);

    string choixJoueurString();
    string choixJoueurString(string text_to_print);

    void printScreen();
    void printScreen(string text);
    void win();
    void lose();

private:
};

#endif
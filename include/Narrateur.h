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
    int prendreArme(Personnage *joueur, Arme *arme);       // Decide if you take Arme or not
    int prendreArmure(Personnage *joueur, Armure *armure); // Decide if you take Armure or not
    int prendreConsommable(Personnage *joueur, Consommable *consommable);
    int useConsommable(vector<Consommable *> liste_consommable);
    int useMagic(Personnage *personnageActuel, vector<Magie *> liste_magies);

    string choixJoueurString();
    string choixJoueurString(string text_to_print);

    void printScreen();
    void printScreen(string text);
    void printEtatCombat2Joueur(vector<Personnage *> joueur1, vector<Personnage *> joueur2); // print all the stat of all the Personnage
    void win();
    void lose();

private:
};

#endif
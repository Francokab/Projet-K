#ifndef NARRATEUR_H
#define NARRATEUR_H

#pragma once

#include <iostream>
#include "personnage.h"
#include "Objet.h"

using namespace std;

class Narrateur
{
public:
    Narrateur();
    ~Narrateur();

    void choix_joueur();
    void print_screen();
    void print_screen(string text);
    void prendre_objet(Personnage* joueur, Objet* objet);
    void win();
    void lose();

private:

};

#endif
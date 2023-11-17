#ifndef NARRATEUR_H
#define NARRATEUR_H

#pragma once

#include <iostream>

using namespace std;

class Narrateur
{
public:
    Narrateur();
    ~Narrateur();

    void choix_joueur();
    void print_screen();
    void print_screen(string text);

private:

};

#endif
#ifndef OBJET_H
#define OBJET_H

#pragma once

#include <iostream>

class Objet
{
public:
    Objet();
    // Objet(std::string nom_, int prix_, int poids_);
    ~Objet(); //standard destructor

    std::string nom;
    // int prix;
    // int poids;

private:
};

#endif
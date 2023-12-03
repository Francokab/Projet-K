#ifndef JOUEUR_H
#define JOUEUR_H

#pragma once

#include <vector>
#include <Personnage.h>
#include "Narrateur.h"

enum JOUEUR_TAG
{ // Determine gameplay role
    TAG_NONE,
    TAG_PLAYER,
    TAG_MONSTRE,
    TAG_CIVIL // not implemented
};

class Joueur
{
public:
    Joueur();
    Joueur(Narrateur *narrateur);
    ~Joueur();

    JOUEUR_TAG joueurTag = TAG_NONE; // Determine gameplay role

    vector<Personnage *> vectorPersonnage;
    virtual void deciderCombat2Joueur(Joueur *joueurEnnemi) = 0; // decide what to do in a combat
    void setNarrateur(Narrateur *narrateur);
    void addPersonnage(Personnage *personnage);
    void removePersonnage(Personnage *personnage); // remove the personnage, does not delete him
    void removeAllPersonage();                     // remove all personnage, does not delete them
    bool isAlive();                                // check if all Personnage are dead

protected:
    Narrateur *narrateur;
};

class JoueurHumain : public Joueur
{
public:
    void deciderCombat2Joueur(Joueur *joueurEnnemi);
    void _choixAttaquerUnEnnemi(Joueur *joueurEnnemi, Personnage *personnageActuel); // logic for attacking an ennemi during combat
    void useConsommable(Joueur *joueurEnnemi, Personnage *personnageActuel);         // logic for using a consommable during combat
    void useMagic(Joueur *joueurEnnemi, Personnage *personnageActuel);               // logic for using magic during combat
    int deciderPath(int numberOfChoice);                                             // decide what Path to tak
    int deciderClasse(int numberOfChoice);                                           // decide what class to take at personnage creation
    string deciderNom();                                                             // choose our name during personnage creation
};
class JoueurMonstre : public Joueur
{
public:
    void deciderCombat2Joueur(Joueur *joueurEnnemi);
};

#endif
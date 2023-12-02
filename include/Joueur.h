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
    virtual int deciderAction(vector<Personnage *> liste_personnage_present, int statut) = 0;
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
    int deciderAction(vector<Personnage *> liste_personnage_present, int statut);
    int deciderPath(int numberOfChoice);
    int deciderClasse(int numberOfChoice);
    string deciderNom();
};
class JoueurMonstre : public Joueur
{
public:
    int deciderAction(vector<Personnage *> liste_personnage_present, int statut);
};

#endif
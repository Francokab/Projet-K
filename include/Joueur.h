#ifndef JOUEUR_H
#define JOUEUR_H

#pragma once

#include <vector>
#include <Personnage.h>

class Joueur
{
public:
    Joueur();
    ~Joueur();

    vector<Personnage*> vectorPersonnage;
    virtual int deciderAction(vector<Personnage *> liste_personnage_present, int statut) = 0;
    void addPersonnage(Personnage* personnage);

private:

};

class JoueurHumain : public Joueur {public: int deciderAction(vector<Personnage *> liste_personnage_present, int statut);};
class JoueurMonstre : public Joueur {public: int deciderAction(vector<Personnage *> liste_personnage_present, int statut);};

#endif
#ifndef JOUEUR_H
#define JOUEUR_H

#pragma once

#include "Personnage.h"

using namespace std;

class Joueurs : public Personnage{

public:

    Joueurs();
    Joueurs(string new_nom, int new_pv, int new_force,
        int new_endurance, int new_vitesse, int new_agilite,
        int new_arcanisme, int new_mana, Arme new_arme, Armure new_armure);

    int deciderAction(vector<Personnage *> liste_personnage_present, int statut) override;

};

#endif
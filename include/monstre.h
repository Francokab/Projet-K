#ifndef MONSTRE_H
#define MONSTRE_H

#pragma once

#include "Personnage.h"

using namespace std;

class Monstre : public Personnage{

public:

    Monstre(string new_nom, int new_pv, int new_force,
        int new_endurance, int new_vitesse, int new_agilite,
        int new_arcanisme, int new_mana, Arme new_arme, Armure new_armure);

    Monstre(string new_nom, int new_pv, int new_force);

    int deciderAction(vector<Personnage *> liste_personnage_present, int statut) override;

};

#endif
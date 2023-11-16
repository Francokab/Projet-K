#ifndef MONSTRE_H
#define MONSTRE_H

#pragma once

#include "personnage.h"

using namespace std;

class Monstre : public Personnage{

public:
    int deciderAction(vector<Personnage *> liste_personnage_present, int statut) override;

};

#endif
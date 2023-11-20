#ifndef CIVIL_H
#define CIVIL_H

#pragma once

#include "Personnage.h"

using namespace std;

class Civil : public Personnage{

public:
    int deciderAction(vector<Personnage *> liste_personnage_present, int statut) override;

};

#endif
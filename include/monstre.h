#ifndef MONSTRE_H
#define MONSTRE_H

#pragma once

#include "personnage.h"

using namespace std;

class Monstre : public Personnage{

public:
    int deciderAction() override;

};

#endif
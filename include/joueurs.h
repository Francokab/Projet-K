#ifndef JOUEUR_H
#define JOUEUR_H

#pragma once

#include "personnage.h"

using namespace std;

class Joueurs : public Personnage{

public:

    void deciderAction() override;

};

#endif
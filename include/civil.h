#ifndef CIVIL_H
#define CIVIL_H

#pragma once

#include "personnage.h"

using namespace std;

class Civil : public Personnage{

public:
    void deciderAction() override;

};

#endif
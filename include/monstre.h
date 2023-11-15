#include "personnage.h"

using namespace std;

class Monstre : public Personnage{

public:
    void deciderAction() override;

};
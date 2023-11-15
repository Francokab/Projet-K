#include "personnage.h"

using namespace std;

class Civil : public Personnage{

public:
    void deciderAction() override;

};
#include "string"
#include "vector"
#include "map"

using namespace std;

class Consommables;
class Armes;
class Armures;

class Personnage {

    void attaquerUnAutrePersonnage(Armes armes, Personnage ennemis);

    void equiper();

    virtual void deciderAction() = 0;


private:
    string nom = "";
    int pv = 0;
    int force = 0;
    int endurance = 0;
    int vitesse = 0;
    int agilite = 0;
    int arcanisme = 0;
    int mana = 0;
    vector<string> competence_liste;
    vector<Consommables> objets_liste;
    vector<Armes> armes_liste;
    vector<Armures> armures_liste;
    map<string, int> statistiques;
};
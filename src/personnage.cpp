#include "personnage.h"

using namespace std;

Personnage::Personnage(){

    //Initialisation des statistiques
    statistiques["Nombre de personnages tués"] = 0;
    statistiques["Nombre de salles parcourues"] = 0;
    statistiques["Nombre d'objets ramassés"] = 0;
    statistiques["Nombre de sorts utilisés"] = 0;
}

Personnage::Personnage(string new_nom, int new_pv, int new_force,
    int new_endurance, int new_vitesse, int new_agilite,
    int new_arcanisme, int new_mana){

    nom = new_nom;
    pv = new_pv;
    force = new_force;
    endurance = new_endurance;
    vitesse = new_vitesse;
    agilite = new_agilite;
    arcanisme = new_arcanisme;
    mana = new_mana;

    //Initialisation des statistiques
    statistiques["Nombre de personnages tués"] = 0;
    statistiques["Nombre de salles parcourues"] = 0;
    statistiques["Nombre d'objets ramassés"] = 0;
    statistiques["Nombre de sorts utilisés"] = 0;
}
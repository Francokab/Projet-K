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
    int new_arcanisme, int new_mana, Arme new_arme, Armure new_armure){

    nom = new_nom;
    pv = new_pv;
    force = new_force;
    endurance = new_endurance;
    vitesse = new_vitesse;
    agilite = new_agilite;
    arcanisme = new_arcanisme;
    mana = new_mana;
    arme_equipe = new_arme;
    armure_equipe = new_armure;

    //Initialisation des statistiques
    statistiques["Nombre de personnages tués"] = 0;
    statistiques["Nombre de salles parcourues"] = 0;
    statistiques["Nombre d'objets ramassés"] = 0;
    statistiques["Nombre de sorts utilisés"] = 0;
}

Personnage::~Personnage() {
    
}

void Personnage::equiper_arme(Arme new_arme){
    arme_equipe = new_arme;
}

void Personnage::equiper_armure(Armure new_armure){
    armure_equipe = new_armure;
}

void Personnage::attaquer_Un_Autre_Personnage(Arme armes, Personnage* ennemis){

    int pv_ennemie = ennemis->get_pv();
    int degats_brut = armes.attaque*(10 + force);
    int degats_net = (degats_brut - ennemis->armure_equipe.defense)/ennemis->endurance;
    ennemis->set_pv(pv_ennemie - degats_net);

}
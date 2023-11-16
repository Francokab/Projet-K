#include "monstre.h"
#include "civil.h"

using namespace std;

Monstre::Monstre(string new_nom, int new_pv, int new_force,
    int new_endurance, int new_vitesse, int new_agilite,
    int new_arcanisme, int new_mana, Arme new_arme, Armure new_armure){


    set_nom(new_nom);
    set_pv(new_pv);
    set_force(new_force);
    set_endurance(new_endurance);
    set_vitesse(new_vitesse);
    set_agilite(new_agilite);
    set_arcanisme(new_arcanisme);
    set_mana(new_mana);
    equiper_arme(new_arme);
    equiper_armure(new_armure);
}

Monstre::Monstre(string new_nom, int new_pv, int new_force){


    set_nom(new_nom);
    set_pv(new_pv);
    set_force(new_force);
    set_endurance(0);
    set_vitesse(0);
    set_agilite(0);
    set_arcanisme(0);
    set_mana(0);
    //equiper_arme(new_arme);
    //equiper_armure(new_armure);
}

int Monstre::deciderAction(vector<Personnage *> liste_personnage_present, int statut){

    for(Personnage *p : liste_personnage_present){   
        if(dynamic_cast<Monstre *>(p) != nullptr){
            //C'est un monstre

        } else if(dynamic_cast<Civil *> (p) != nullptr){
            //C'est un civil

        } else {
            //C'est un joueur
            attaquer_Un_Autre_Personnage(get_arme_equipe(), p);
        }
    }

    return 0;

}
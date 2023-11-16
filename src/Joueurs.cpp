#include "joueurs.h"
#include "monstre.h"
#include "civil.h"

#define EXPLORATION 0
#define BATTLE 1

using namespace std;

Joueurs::Joueurs(string new_nom, int new_pv, int new_force,
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

int Joueurs::deciderAction(vector<Personnage *> liste_personnage_present, int statut){
    int choix_int = 0;
    switch(statut){

        case BATTLE:
            
            for(Personnage *p : liste_personnage_present){
            //Le but est de trouver tous les types de personnage présents dans la salle

                if(dynamic_cast<Monstre *>(p) != nullptr){
                    //C'est le monstre à combattre
                    cout << "Que voulez-vous faire ? Attaquer : 1, Fuir : 2" << endl;
                    string choix = "";
                    int choix_battle = 0;
                    bool exception_present = 1;

                    while(exception_present) {
                        cin >> choix;
                        try {
                            choix_battle = stoi(choix); 
                            exception_present = 0;
                        } catch (exception()) {
                            cout << "N'utiliser que 1 ou 2 en chiffre." << endl;
                        }
                    }

                    if(choix_battle == 1) {attaquer_Un_Autre_Personnage(get_arme_equipe(), p);}
                    if(choix_battle == 2) {}//TODO Implémenter fonction fuir


                } else if(dynamic_cast<Civil *> (p) != nullptr){
                    //C'est un civil

                } else {
                    //C'est un joueur

                }
        }

        break;

        case EXPLORATION:
        
            string choix = "";
            int choix_int = 0;
            bool exception_present = 1;
            while(exception_present) {

                //On essaye de pouvoir capter les erreurs dans l'écriture du choix des joueurs dans le terminal
                cin >> choix;
                try {
                    choix_int = stoi(choix); 
                    exception_present = 0;
                } catch (exception()) {
                    cout << "N'utiliser que 1 ou 2 en chiffre." << endl;
                }
            }

            break;
    }


    return choix_int;
}
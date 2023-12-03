#include "Magie.h"
#include <iostream>
#include "personnage.h"
#include "Joueur.h"

using namespace std;

Magie::Magie() : manaPrix(0), nbrUtilisationMax(5)
{
}

Magie::Magie(int manaPrix_, int nbrUtilisationMax_) : manaPrix(manaPrix_), nbrUtilisationMax(nbrUtilisationMax_)
{
}

Magie::Magie(std::string nom_, int manaPrix_, int nbrUtilisationMax_)
{
    nom = nom_;
    // prix = 0;
    // poids = 0;
    manaPrix = manaPrix_;
    nbrUtilisationMax = nbrUtilisationMax_;
}

/* Magie::Magie(std::string nom_, int prix_, int poids_, int manaPrix_, int nbrUtilisationMax_)
{
    nom = nom_;
    prix = prix_;
    poids = poids_;
    manaPrix = manaPrix_;
    nbrUtilisationMax = nbrUtilisationMax_;
} */

Magie::~Magie()
{
}

BouleDeFeu::BouleDeFeu(string nom_, int manaPrix_, int nbrUtilisationMax_){
    nom = nom_;
    manaPrix = manaPrix_;
    nbrUtilisationMax = nbrUtilisationMax_;
}

void BouleDeFeu::effet(Joueur *joueurEnnemi, Personnage *personnageActuel)
{
    personnageActuel->set_mana(personnageActuel->get_mana() - manaPrix);

    cout << "Boule de feu !" << endl;

    Personnage *PersonnageAAttaquer;
    for (Personnage *personnageEnnemi : joueurEnnemi->vectorPersonnage)
    {
        if (personnageEnnemi->isAlive())
        {
            PersonnageAAttaquer = personnageEnnemi;
            break;
        }
    }
    PersonnageAAttaquer->set_pv(PersonnageAAttaquer->get_pv() - 50);
    cout << PersonnageAAttaquer->get_nom() << " perd 30 points de vie !" << endl;
    cout << PersonnageAAttaquer->get_nom() << " a " << PersonnageAAttaquer->get_pv() << " point de vie." << endl;
}
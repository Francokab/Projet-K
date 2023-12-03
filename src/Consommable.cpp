#include "Consommable.h"
#include "Personnage.h"
#include "Joueur.h"
#include <iostream>
#include <string>


Consommable::Consommable()
{
}

Consommable::Consommable(string nom, int prix){
    this->nom = nom;
    this->prix = prix;
}

Consommable::~Consommable()
{
}


PotionDeVie::PotionDeVie(string nom, int prix){
    this->nom = nom;
    this->prix = prix;

}
void PotionDeVie::effet(Joueur *joueurEnnemi, Personnage *personnageActuel)
{
    cout << "Vous utilisez une potion de vie, vous regagnez 50 points de vie." << endl;
    personnageActuel->set_pv(personnageActuel->get_pv() + 50);
}

Bombe::Bombe(string nom, int prix){
    this->nom = nom;
    this->prix = prix;
}

void Bombe::effet(Joueur *joueurEnnemi, Personnage *personnageActuel)
{
    cout << "Vous utilisez une bombe !" << endl;
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
    cout << PersonnageAAttaquer->get_nom() << " perd 50 points de vie !" << endl;
    cout << PersonnageAAttaquer->get_nom() << " a " << PersonnageAAttaquer->get_pv() << " point de vie." << endl;
    
}


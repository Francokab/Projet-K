#include "Personnage.h"

using namespace std;

Personnage::Personnage()
{

    // Initialisation des statistiques
    statistiques["Nombre de personnages tués"] = 0;
    statistiques["Nombre de salles parcourues"] = 0;
    statistiques["Nombre d'objets ramassés"] = 0;
    statistiques["Nombre de sorts utilisés"] = 0;
}

Personnage::Personnage(string new_nom, int new_pv, int new_force,
                       int new_endurance, int new_vitesse, int new_agilite,
                       int new_arcanisme, int new_mana, Arme *new_arme, Armure *new_armure)
{

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

    // Initialisation des statistiques
    statistiques["Nombre de personnages tués"] = 0;
    statistiques["Nombre de salles parcourues"] = 0;
    statistiques["Nombre d'objets ramassés"] = 0;
    statistiques["Nombre de sorts utilisés"] = 0;
}

Personnage::Personnage(string new_nom, int new_pv, int new_force)
{

    set_nom(new_nom);
    set_pv(new_pv);
    set_force(new_force);
    set_endurance(0);
    set_vitesse(0);
    set_agilite(0);
    set_arcanisme(0);
    set_mana(0);
    // equiper_arme(new_arme);
    // equiper_armure(new_armure);
}

Personnage::~Personnage()
{
}

void Personnage::equiper_arme(Arme *new_arme)
{
    arme_equipe = new_arme;
}

void Personnage::equiper_armure(Armure *new_armure)
{
    armure_equipe = new_armure;
}

void Personnage::attaquer_Un_Autre_Personnage(Arme *armes, Personnage *ennemis)
{

    int pv_ennemie = ennemis->get_pv();
    int degats_brut = armes->attaque * (10 + force);
    int degats_net = (degats_brut - ennemis->armure_equipe->defense) / ennemis->endurance;
    ennemis->set_pv(pv_ennemie - degats_net);
}

void Personnage::add_competence(string *competence)
{
}

void Personnage::add_consommable(Consommable *conso)
{
}

void Personnage::add_arme(Arme *arme)
{
}

void Personnage::add_armure(Armure *armure)
{
}

void Personnage::del_competence(string *competence)
{
}

void del_consommable(Consommable *conso)
{
}

void del_arme(Arme *arme)
{
}

void del_armure(Armure *armure)
{
}

void raz_competences()
{
}

void raz_consommables()
{
}

void raz_armes()
{
}

void raz_armures()
{
}
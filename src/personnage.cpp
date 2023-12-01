#include "Personnage.h"
#include <algorithm>

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
    add_equip_arme(new_arme);
    add_equip_armure(new_armure);

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

void Personnage::add_competence(SKILL competence)
{
    competences_liste.push_back(competence);
}

void Personnage::add_consommable(Consommable *conso)
{
    consommables_liste.push_back(conso);
}

void Personnage::add_arme(Arme *arme)
{
    armes_liste.push_back(arme);
}

void Personnage::add_armure(Armure *armure)
{
    armures_liste.push_back(armure);
}

void Personnage::add_equip_arme(Arme *arme)
{
    add_arme(arme);
    equiper_arme(arme);
}

void Personnage::add_equip_armure(Armure *armure)
{
    add_armure(armure);
    equiper_armure(armure);
}

void Personnage::del_competence(SKILL competence)
{
    std::vector<SKILL>::iterator position = std::find(competences_liste.begin(), competences_liste.end(), competence);
    if (position != competences_liste.end())
    { // == vectorPersonnage.end() means the element was not found
        competences_liste.erase(position);
    }
}

void Personnage::del_consommable(Consommable *conso)
{
    std::vector<Consommable *>::iterator position = std::find(consommables_liste.begin(), consommables_liste.end(), conso);
    if (position != consommables_liste.end())
    { // == vectorPersonnage.end() means the element was not found
        consommables_liste.erase(position);
    }
}

void Personnage::del_arme(Arme *arme)
{
    std::vector<Arme *>::iterator position = std::find(armes_liste.begin(), armes_liste.end(), arme);
    if (position != armes_liste.end())
    { // == vectorPersonnage.end() means the element was not found
        armes_liste.erase(position);
    }
}

void Personnage::del_armure(Armure *armure)
{
    std::vector<Armure *>::iterator position = std::find(armures_liste.begin(), armures_liste.end(), armure);
    if (position != armures_liste.end())
    { // == vectorPersonnage.end() means the element was not found
        armures_liste.erase(position);
    }
}
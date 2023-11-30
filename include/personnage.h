#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#pragma once

#include "string"
#include "vector"
#include "map"
#include "Consommable.h"
#include "Arme.h"
#include "Armure.h"

using namespace std;

class Personnage
{

public:
    // Constructor
    Personnage();
    Personnage(string new_nom, int new_pv, int new_force,
               int new_endurance, int new_vitesse, int new_agilite,
               int new_arcanisme, int new_mana, Arme *new_arme, Armure *new_armure);
    Personnage(string new_nom, int new_pv, int new_force);

    // Destructor
    ~Personnage();

    // Operations principales de la classe personnage
    void attaquer_Un_Autre_Personnage(Arme *armes, Personnage *ennemis);
    void equiper_arme(Arme *new_arme);
    void equiper_armure(Armure *new_armure);

    // Getter
    string get_nom() { return nom; }
    int get_pv() { return pv; }
    int get_force() { return force; }
    int get_endurance() { return endurance; }
    int get_vitesse() { return vitesse; }
    int get_agilite() { return agilite; }
    int get_arcanisme() { return arcanisme; }
    int get_mana() { return mana; }
    Arme *get_arme_equipe() { return arme_equipe; }
    Armure *get_armure_equipe() { return armure_equipe; }
    vector<string *> get_competences() { return competences_liste; }
    vector<Consommable *> get_consommables() { return consommables_liste; }
    vector<Arme *> get_armes() { return armes_liste; }
    vector<Armure *> get_armures() { return armures_liste; }
    map<string, int> get_statistiques() { return statistiques; }

    // Setter
    void set_nom(string new_nom) { nom = new_nom; }
    void set_pv(int new_pv) { pv = new_pv; }
    void set_force(int new_force) { force = new_force; }
    void set_endurance(int new_endurance) { endurance = new_endurance; }
    void set_vitesse(int new_vitesse) { vitesse = new_vitesse; }
    void set_agilite(int new_agilite) { agilite = new_agilite; }
    void set_arcanisme(int new_arcanisme) { arcanisme = new_arcanisme; }
    void set_mana(int new_mana) { mana = new_mana; }

    // Pour les listes de competences et des objets,
    // il nous semble plus pertinent de mettre les setters sous la
    // forme d'un push_back, d'un pop ou d'une remise à zéro.
    void add_competence(string *competence);
    void add_consommable(Consommable *conso);
    void add_arme(Arme *arme);
    void add_armure(Armure *armure);

    void add_equip_arme(Arme *arme);
    void add_equip_armure(Armure *armure);

    void del_competence(string *competence);
    void del_consommable(Consommable *conso);
    void del_arme(Arme *arme);
    void del_armure(Armure *armure);

    // void raz_competences();
    // void raz_consommables();
    // void raz_armes();
    // void raz_armures();

    // Les statistiques sont théoriquement toujours les mêmes, mais
    // elles peuvent être incrémentés.
    void add_stats(string statistiques_incrementable);

private:
    string nom = "";
    int pv = 0;
    int force = 0;
    int endurance = 0;
    int vitesse = 0;
    int agilite = 0;
    int arcanisme = 0;
    int mana = 0;
    Arme *arme_equipe;
    Armure *armure_equipe;
    vector<string*> competences_liste;
    vector<Consommable *> consommables_liste;
    vector<Arme *> armes_liste;
    vector<Armure *> armures_liste;
    map<string, int> statistiques;
};

#endif
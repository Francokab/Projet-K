#include "Catalogue.h"
#include "Personnage.h"
#include "Jeu.h"

Catalogue::Catalogue()
{
}

Catalogue::Catalogue(Jeu *jeu)
{
    this->jeu = jeu;
}

Catalogue::~Catalogue()
{
}

Personnage *Catalogue::basic()
{
    Arme *poing = Catalogue::poing();
    Armure *peau = Catalogue::peau();
    Personnage *joueur = new Personnage();
    jeu->vectorPersonnage.push_back(joueur);
    joueur->set_nom("Basic");
    joueur->set_pv(100);
    joueur->set_force(5);
    // joueur->set_endurance(5);
    // joueur->set_vitesse(5);
    // joueur->set_agilite(5);
    // joueur->set_arcanisme(0);
    joueur->set_mana(0);
    joueur->add_equip_arme(poing);
    joueur->add_equip_armure(peau);

    return joueur;
}

Personnage *Catalogue::basic(string nom, int pv, int force)
{
    Personnage *joueur = basic();
    joueur->set_nom(nom);
    joueur->set_pv(pv);
    joueur->set_force(force);
    return joueur;
}

Personnage *Catalogue::artificier()
{
    Arme *poing = Catalogue::poing();
    Armure *cuirasse = Catalogue::cuirasse();
    Personnage *joueur = basic();
    jeu->vectorPersonnage.push_back(joueur);
    joueur->set_nom("Artificier");
    joueur->set_pv(100);
    joueur->set_force(0);
    joueur->set_mana(0);
    joueur->add_equip_arme(poing);
    joueur->add_equip_armure(cuirasse);
    Consommable *bombe = Catalogue::bombe();
    Consommable *potionDeVie = Catalogue::potionDeVie();
    joueur->add_consommable(bombe);
    joueur->add_consommable(bombe);
    joueur->add_consommable(bombe);
    joueur->add_consommable(bombe);
    joueur->add_consommable(potionDeVie);

    return joueur;
}

Personnage *Catalogue::guerrier()
{
    Arme *epee = Catalogue::epee();
    Armure *cuirasse = Catalogue::cuirasse();
    Personnage *joueur = basic();
    jeu->vectorPersonnage.push_back(joueur);
    joueur->set_nom("Guerrier");
    joueur->set_pv(35);
    joueur->set_force(4);
    // joueur->set_endurance(7);
    // joueur->set_vitesse(7);
    // joueur->set_agilite(7);
    // joueur->set_arcanisme(7);
    joueur->set_mana(0);
    joueur->add_equip_arme(epee);
    joueur->add_equip_armure(cuirasse);

    return joueur;
}

Personnage *Catalogue::rodeur()
{
    Arme *dagues = Catalogue::dagues();
    Armure *cuir = Catalogue::cuir();
    Personnage *joueur = basic();
    jeu->vectorPersonnage.push_back(joueur);
    joueur->set_nom("Rodeur");
    joueur->set_pv(25);
    joueur->set_force(4);
    // joueur->set_endurance(8);
    // joueur->set_vitesse(8);
    // joueur->set_agilite(9);
    // joueur->set_arcanisme(0);
    joueur->set_mana(0);
    joueur->add_equip_arme(dagues);
    joueur->add_equip_armure(cuir);
    joueur->add_competence(SKILL_CRIT_RODEUR);
    joueur->add_competence(SKILL_ESQUIVE_RODEUR);

    return joueur;
}

Personnage *Catalogue::mage()
{
    Arme *baton = Catalogue::baton();
    Armure *tissus = Catalogue::tissus();
    Personnage *joueur = basic();
    jeu->vectorPersonnage.push_back(joueur);
    joueur->set_nom("Mage");
    joueur->set_pv(100);
    joueur->set_force(3);
    // joueur->set_endurance(5);
    // joueur->set_vitesse(5);
    // joueur->set_agilite(4);
    // joueur->set_arcanisme(8);
    joueur->set_mana(100);
    joueur->add_equip_arme(baton);
    joueur->add_equip_armure(tissus);

    return joueur;
}

Arme *Catalogue::armeBasic(std::string nom_, int attaque_)
{
    Arme *armeBasic = new Arme(nom_, attaque_);
    jeu->vectorObjet.push_back(armeBasic);
    return armeBasic;
}

Arme *Catalogue::poing()
{
    Arme *poing = new Arme("Coup de poing", 1);
    jeu->vectorObjet.push_back(poing);
    return poing;
}

Arme *Catalogue::epee()
{

    Arme *epee = new Arme("Epee en fer", 4);
    jeu->vectorObjet.push_back(epee);
    return epee;
}

Arme *Catalogue::dagues()
{
    Arme *dagues = new Arme("Dague en fer", 3);
    jeu->vectorObjet.push_back(dagues);
    return dagues;
}

Arme *Catalogue::baton()
{
    Arme *baton = new Arme("Baton en bois", 2);
    jeu->vectorObjet.push_back(baton);
    return baton;
}

Armure *Catalogue::armureBasic(std::string nom_, int defense_)
{
    Armure *armureBasic = new Armure(nom_, defense_);
    jeu->vectorObjet.push_back(armureBasic);
    return armureBasic;
}

Armure *Catalogue::peau()
{
    Armure *peau = new Armure("Peau", 1);
    jeu->vectorObjet.push_back(peau);
    return peau;
}

Armure *Catalogue::cuirasse()
{

    Armure *cuirasse = new Armure("Cuirasse en maille", 4);
    jeu->vectorObjet.push_back(cuirasse);
    return cuirasse;
}

Armure *Catalogue::cuir()
{
    Armure *cuir = new Armure("Armure en cuir", 3);
    jeu->vectorObjet.push_back(cuir);
    return cuir;
}

Armure *Catalogue::tissus()
{
    Armure *tissus = new Armure("Vetements en tissus", 2);
    jeu->vectorObjet.push_back(tissus);
    return tissus;
}

Consommable *Catalogue::bombe(){
    Bombe *bombe = new Bombe("Bombe", 25);
    return bombe;
}

Consommable *Catalogue::potionDeVie(){
    PotionDeVie *potion = new PotionDeVie("Potion de vie", 25);
    return potion;
}
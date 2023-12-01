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
    joueur->set_endurance(5);
    joueur->set_vitesse(5);
    joueur->set_agilite(5);
    joueur->set_arcanisme(0);
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

Personnage *Catalogue::guerrier()
{
    Arme *epee = Catalogue::epee();
    Armure *cuirasse = Catalogue::cuirasse();
    Personnage *joueur = basic();
    jeu->vectorPersonnage.push_back(joueur);
    joueur->set_nom("Guerrier");
    joueur->set_pv(100);
    joueur->set_force(7);
    joueur->set_endurance(7);
    joueur->set_vitesse(7);
    joueur->set_agilite(7);
    joueur->set_arcanisme(7);
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
    joueur->set_pv(100);
    joueur->set_force(5);
    joueur->set_endurance(8);
    joueur->set_vitesse(8);
    joueur->set_agilite(9);
    joueur->set_arcanisme(0);
    joueur->set_mana(0);
    joueur->add_equip_arme(dagues);
    joueur->add_equip_armure(cuir);

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
    joueur->set_endurance(5);
    joueur->set_vitesse(5);
    joueur->set_agilite(4);
    joueur->set_arcanisme(8);
    joueur->set_mana(100);
    joueur->add_equip_arme(baton);
    joueur->add_equip_armure(tissus);

    return joueur;
}

Arme *Catalogue::poing()
{
    Arme *poing = new Arme("Coup de poing", 0, 0, 1);
    jeu->vectorObjet.push_back(poing);
    return poing;
}

Arme *Catalogue::epee()
{

    Arme *epee = new Arme("Epee en fer", 25, 7, 6);
    jeu->vectorObjet.push_back(epee);
    return epee;
}

Arme *Catalogue::dagues()
{
    Arme *dagues = new Arme("Dague en fer", 12, 3, 4);
    jeu->vectorObjet.push_back(dagues);
    return dagues;
}

Arme *Catalogue::baton()
{
    Arme *baton = new Arme("Baton en bois", 5, 1, 2);
    jeu->vectorObjet.push_back(baton);
    return baton;
}

Armure *Catalogue::peau()
{
    Armure *peau = new Armure("Peau", 0, 0, 1);
    jeu->vectorObjet.push_back(peau);
    return peau;
}

Armure *Catalogue::cuirasse()
{

    Armure *cuirasse = new Armure("Cuirasse en maille", 75, 15, 7);
    jeu->vectorObjet.push_back(cuirasse);
    return cuirasse;
}

Armure *Catalogue::cuir()
{
    Armure *cuir = new Armure("Armure en cuir", 40, 10, 5);
    jeu->vectorObjet.push_back(cuir);
    return cuir;
}

Armure *Catalogue::tissus()
{
    Armure *tissus = new Armure("Vetements en tissus", 10, 2, 2);
    jeu->vectorObjet.push_back(tissus);
    return tissus;
}

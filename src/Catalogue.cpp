#include "Catalogue.h"
#include "Personnage.h"

Catalogue::Catalogue()
{
}

Catalogue::~Catalogue()
{
}

Personnage *Catalogue::guerrier()
{

    Arme *epee = Catalogue::epee();
    Armure *cuirasse = Catalogue::cuirasse();
    Personnage *joueur = new Personnage();
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
    Personnage *joueur = new Personnage();
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
    Personnage *joueur = new Personnage();
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

Arme *Catalogue::epee()
{

    Arme *epee = new Arme("Epee en fer", 25, 7, 6);
    return epee;
}

Arme *Catalogue::dagues()
{
    Arme *dagues = new Arme("Dague en fer", 12, 3, 4);
    return dagues;
}

Arme *Catalogue::baton()
{
    Arme *baton = new Arme("Baton en bois", 5, 1, 2);
    return baton;
}

Armure *Catalogue::cuirasse()
{

    Armure *cuirasse = new Armure("Cuirasse en maille", 75, 15, 7);
    return cuirasse;
}

Armure *Catalogue::cuir()
{
    Armure *cuir = new Armure("Armure en cuir", 40, 10, 5);
    return cuir;
}

Armure *Catalogue::tissus()
{
    Armure *tissus = new Armure("Vetements en tissus", 10, 2, 1);
    return tissus;
}

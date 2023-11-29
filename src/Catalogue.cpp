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
    Personnage *joueur = new Personnage("Joueur", 100, 7, 7, 7, 7, 7, 0, epee, cuirasse);

    return joueur;
}

Personnage *Catalogue::rodeur()
{
    Arme *dagues = Catalogue::dagues();
    Armure *cuir = Catalogue::cuir();
    Personnage *joueur = new Personnage("Joueur", 100, 5, 8, 8, 9, 0, 0, dagues, cuir);

    return joueur;
}

Personnage *Catalogue::mage()
{
    Arme *baton = Catalogue::baton();
    Armure *tissus = Catalogue::tissus();
    Personnage *joueur = new Personnage("Joueur", 100, 3, 5, 5, 4, 8, 100, baton, tissus);

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
    return new Armure();
}

Armure *Catalogue::tissus()
{
    return new Armure();
}

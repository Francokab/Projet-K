#include "Catalogue.h"
#include "joueurs.h"
#include "personnage.h"

Catalogue::Catalogue()
{

}

Catalogue::~Catalogue()
{

}

Personnage Catalogue::guerrier(){

    Arme epee = Catalogue::epee();
    Armure cuirasse = Catalogue::cuirasse();
    Personnage joueur = Personnage("Joueur", 100, 7, 7, 7, 7, 7, 0, epee, cuirasse);
    
    return joueur;
}

Personnage Catalogue::rodeur(){
    Arme dagues = Catalogue::dagues();
    Armure cuir = Catalogue::cuir();
    Personnage joueur = Personnage("Joueur", 100, 5, 8, 8, 9, 0, 0, dagues, cuir);

    return joueur;
}

Personnage Catalogue::mage(){
    Arme baton = baton();
    Armure tissus = tissus();
    Personnage joueur = Personnage("Joueur", 100, 3, 5, 5, 4, 8, 100, baton, tissus);

    return joueur;
}

Arme Catalogue::epee(){

    Arme epee = Arme("Epee en fer", 25, 7, 6);
    return epee;
}

Arme Catalogue::dagues(){
    Arme dagues = Arme("Dague en fer", 12, 3, 4);
    return dagues;
}

Arme Catalogue::baton() {
    Arme baton = Arme("Baton en bois", 5, 1, 2);
    return baton;
}

Armure Catalogue::cuirasse(){

    Armure cuirasse = Armure("Cuirasse en maille", 75, 15, 7);
    return cuirasse;
}
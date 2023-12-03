#include "Joueur.h"
#include <algorithm>
#define EXPLORATION 0
#define BATTLE 1

Joueur::Joueur()
{
}

Joueur::Joueur(Narrateur *narrateur)
{
    this->setNarrateur(narrateur);
}

Joueur::~Joueur()
{
}

void Joueur::setNarrateur(Narrateur *narrateur)
{
    this->narrateur = narrateur;
}

void Joueur::addPersonnage(Personnage *personnage)
{
    vectorPersonnage.push_back(personnage);
}

void Joueur::removePersonnage(Personnage *personnage)
{
    std::vector<Personnage *>::iterator position = std::find(vectorPersonnage.begin(), vectorPersonnage.end(), personnage);
    if (position != vectorPersonnage.end())
    { // == vectorPersonnage.end() means the element was not found
        vectorPersonnage.erase(position);
    }
}

void Joueur::removeAllPersonage()
{
    vectorPersonnage.clear();
}

bool Joueur::isAlive()
{
    for (Personnage *p : vectorPersonnage)
    {
        if (p->isAlive())
        { // if atleast one is alive return true
            return true;
        }
    }
    return false;
}

void JoueurHumain::deciderCombat2Joueur(Joueur *joueurEnnemi)
{
    for (Personnage *personnageActuel : vectorPersonnage)
    {
        string messageChoix = "1 : Attaquer un ennemi \n2 : Utiliser un consommable \n3 : Utiliser de la magie \n4 : Changer d'arme ou armure \n";

        narrateur->printEtatCombat2Joueur(this->vectorPersonnage, joueurEnnemi->vectorPersonnage);
        narrateur->printScreen(personnageActuel->get_nom() + " doit choisir une action \n");

        switch (narrateur->choixJoueurInt(messageChoix, 1, 4))
        {
        case 1: // Attaquer un ennemi
            _choixAttaquerUnEnnemi(joueurEnnemi, personnageActuel);
            break;

        case 2:
            useConsommable(joueurEnnemi, personnageActuel);
            break;

        case 3:
            useMagic(joueurEnnemi, personnageActuel);
            break;

        default:
            break;
        }
    }
}

void JoueurHumain::useMagic(Joueur *joueurEnnemi, Personnage *personnageActuel){
    vector<Magie *> magies_liste = personnageActuel->get_magie();
    int choix = narrateur->useMagic(personnageActuel, magies_liste);
    if(choix != -1){
        Magie* magie = magies_liste.at(choix);
        magie->effet(joueurEnnemi, personnageActuel);
    }
}

void JoueurHumain::_choixAttaquerUnEnnemi(Joueur *joueurEnnemi, Personnage *personnageActuel)
{
    // print effet de l'arme ?
    Personnage *personnageAAttaquer;
    if (joueurEnnemi->vectorPersonnage.size() > 1)
    {
        string messageEnnemi = "Quel ennemi voulez-vous attaquer ? \n";
        for (long long unsigned int i = 0; i < joueurEnnemi->vectorPersonnage.size(); i++)
        {
            messageEnnemi = messageEnnemi + to_string(i + 1) + " : " + joueurEnnemi->vectorPersonnage[i]->get_nom() + "\n";
        }
        int choixEnnemi = narrateur->choixJoueurInt(messageEnnemi, 1, joueurEnnemi->vectorPersonnage.size());
        personnageAAttaquer = joueurEnnemi->vectorPersonnage[choixEnnemi - 1];
    }
    else if (joueurEnnemi->vectorPersonnage.size() == 1)
    {
        personnageAAttaquer = joueurEnnemi->vectorPersonnage[0];
    }
    else // no ennemi ?
    {
        throw exception();
    }
    string messageAction = personnageActuel->attaquer_Un_Autre_Personnage(personnageAAttaquer);
    narrateur->printScreen(messageAction);
}

void JoueurHumain::useConsommable(Joueur *joueurEnnemi, Personnage *personnageActuel){
    vector<Consommable *> consommables_liste = personnageActuel->get_consommables();
    int choix = narrateur->useConsommable(consommables_liste);
    if(choix != -1){
        Consommable* cons = consommables_liste.at(choix);
        personnageActuel->del_consommable(cons);
        cons->effet(joueurEnnemi, personnageActuel);
    }
}

int JoueurHumain::deciderPath(int numberOfChoice)
{
    return narrateur->choixJoueurInt(1, numberOfChoice + 1) - 1;
}

int JoueurHumain::deciderClasse(int numberOfChoice)
{
    return narrateur->choixJoueurInt(1, numberOfChoice + 1);
}

string JoueurHumain::deciderNom()
{
    return narrateur->choixJoueurString();
}

void JoueurMonstre::deciderCombat2Joueur(Joueur *joueurEnnemi)
{
    for (Personnage *personnageActuel : vectorPersonnage)
    {
        Personnage *PersonnageAAttaquer;
        for (Personnage *personnageEnnemi : joueurEnnemi->vectorPersonnage)
        {
            if (personnageEnnemi->isAlive())
            {
                PersonnageAAttaquer = personnageEnnemi;
                break;
            }
        }
        string message = personnageActuel->attaquer_Un_Autre_Personnage(PersonnageAAttaquer);
        narrateur->printScreen(message);
    }
}

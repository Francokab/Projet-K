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
        if (p->get_pv() > 0)
        { // if atleast one is alive return true
            return true;
        }
    }
    return false;
}

int JoueurMonstre::deciderAction(vector<Personnage *> liste_personnage_present, int statut)
{

    for (Personnage *p : liste_personnage_present)
    {
        vectorPersonnage[0]->attaquer_Un_Autre_Personnage(vectorPersonnage[0]->get_arme_equipe(), p);
    }

    return 0;
}

int JoueurHumain::deciderAction(vector<Personnage *> liste_personnage_present, int statut)
{
    int choix_int = 0;
    switch (statut)
    {

    case BATTLE:

        for (Personnage *p : liste_personnage_present)
        {
            // Le but est de trouver tous les types de personnage présents dans la salle
            // C'est le monstre à combattre
            cout << "Que voulez-vous faire ? Attaquer : 1, Fuir : 2" << endl;
            string choix = "";
            int choix_battle = 0;
            bool exception_present = 1;

            while (exception_present)
            {
                cin >> choix;
                try
                {
                    choix_battle = stoi(choix);
                    exception_present = 0;
                }
                catch (exception())
                {
                    cout << "N'utiliser que 1 ou 2 en chiffre." << endl;
                }
            }

            if (choix_battle == 1)
            {
                vectorPersonnage[0]->attaquer_Un_Autre_Personnage(vectorPersonnage[0]->get_arme_equipe(), p);
            }
            if (choix_battle == 2)
            {
            } // TODO Implémenter fonction fuir
        }

        break;

    case EXPLORATION:

        string choix = "";
        int choix_int = 0;
        bool exception_present = 1;
        while (exception_present)
        {

            // On essaye de pouvoir capter les erreurs dans l'écriture du choix des joueurs dans le terminal
            cin >> choix;
            try
            {
                choix_int = stoi(choix);
                exception_present = 0;
            }
            catch (exception())
            {
                cout << "N'utiliser que 1 ou 2 en chiffre." << endl;
            }
        }

        break;
    }

    return choix_int;
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

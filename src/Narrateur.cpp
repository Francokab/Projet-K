#include "Narrateur.h"
#include "Personnage.h"
#include "Objet.h"
#include <thread>

Narrateur::Narrateur()
{
}

Narrateur::~Narrateur()
{
}

int Narrateur::choixJoueurInt()
{
    int choix;
    cin >> choix;
    cout << endl;
    return choix;
}

int Narrateur::choixJoueurInt(string text_to_print)
{
    printScreen(text_to_print);
    return choixJoueurInt();
}

int Narrateur::choixJoueurInt(int max)
{
    int choix = choixJoueurInt();
    while (choix >= max)
    {
        printScreen("La valeur entrée dépasse le max possible de " + to_string(max));
        choix = choixJoueurInt();
    }
    return choix;
}

int Narrateur::choixJoueurInt(int min, int max)
{
    int choix = choixJoueurInt(max);
    while (choix < min)
    {
        printScreen("La valeur entrée est inférieur au min possible de " + to_string(min));
        choix = choixJoueurInt(max);
    }
    return choix;
}

int Narrateur::choixJoueurInt(string text_to_print, int max)
{
    printScreen(text_to_print);
    return choixJoueurInt(max);
}

int Narrateur::choixJoueurInt(string text_to_print, int min, int max)
{
    printScreen(text_to_print);
    return choixJoueurInt(min, max);
}

string Narrateur::choixJoueurString()
{
    string choix;
    cin >> choix;
    cout << endl;
    return choix;
}

string Narrateur::choixJoueurString(string text_to_print)
{
    printScreen(text_to_print);
    return choixJoueurString();
}

void Narrateur::printScreen()
{
}

void Narrateur::printScreen(string text)
{
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << text << endl;
}

void Narrateur::printEtatCombat2Joueur(vector<Personnage *> joueur1, vector<Personnage *> joueur2)
{
    string messageToPrint = "Vos personnages sont : \n";
    for (Personnage *p : joueur1)
    {
        messageToPrint += p->get_nom() + " a " + to_string(p->get_pv()) + " PV\n";
    }
    messageToPrint += "Les personnages ennemies sont : \n";
    for (Personnage *p : joueur2)
    {
        messageToPrint += p->get_nom() + " a " + to_string(p->get_pv()) + " PV\n";
    }
    printScreen(messageToPrint);
}

int Narrateur::prendreArme(Personnage *joueur, Arme *arme)
{
    cout << "Vous trouvez une " << arme->nom << " sur le sol." << endl;
    cout << "Son attaque est de : " << arme->attaque << ". La votre est de : " << joueur->get_arme_equipe()->attaque << endl;

    int choix = choixJoueurInt("Souhaitez-vous l'équiper ? 0 : Non. 1 : Oui.", 0, 2);

    if (choix == 1)
    {
        cout << joueur->get_nom() << " prend l'arme " << arme->nom << endl;
    }
    else
    {
        cout << joueur->get_nom() << " laisse l'arme " << arme->nom << endl;
    }
    return choix;
}

int Narrateur::prendreArmure(Personnage *joueur, Armure *armure)
{
    cout << "Vous trouvez une " << armure->nom << " sur le sol." << endl;
    cout << "Sa défense est de : " << armure->defense << ". La votre est de : " << joueur->get_armure_equipe()->defense << endl;

    int choix = choixJoueurInt("Souhaitez-vous l'équiper ? 0 : Non. 1 : Oui.", 0, 2);

    if (choix == 1)
    {
        cout << joueur->get_nom() << " prend l'armure " << armure->nom << endl;
    }
    else
    {
        cout << joueur->get_nom() << " laisse l'armure " << armure->nom << endl;
    }

    return choix;
}

int Narrateur::prendreConsommable(Personnage *joueur, Consommable *consommable)
{
    cout << "Vous trouvez un " << consommable->nom << " sur le sol." << endl;
    cout << joueur->get_nom() << " prend l'objet " << consommable->nom << endl;

    int choix = 0;

    return choix;
}

void Narrateur::win()
{
    cout << "Dans ce monde, personne ne vous arrive à la cheville." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Vous avez gagné !" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "A vous la retraite." << endl;
    cout << endl;
}

void Narrateur::lose()
{
    cout << "Tout le courage du monde ne suffit parfois pas..." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Vous etes mort !!!!!" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "RIP" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << endl;
}

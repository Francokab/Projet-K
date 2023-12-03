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

void Narrateur::prendreObjet(Personnage *joueur, Objet *objet)
{
    cout << joueur->get_nom() << " prend l'objet " << objet->nom << endl;
}

void Narrateur::win()
{
    cout << "Dans ce monde, peu vous arrive à la cheville." << endl;
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

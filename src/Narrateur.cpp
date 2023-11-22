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
    return choix;
}

int Narrateur::choixJoueurInt(string text_to_print)
{
    printScreen(text_to_print);
    return choixJoueurInt();
}

string Narrateur::choixJoueurString()
{
    string choix;
    cin >> choix;
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

void Narrateur::printScreen(string text){
    cout << text << endl;
}

void Narrateur::prendreObjet(Personnage* joueur, Objet* objet) {
    cout << joueur->get_nom() << "prend l'objet" << objet->nom << endl;
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

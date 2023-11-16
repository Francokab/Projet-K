#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#include "AllFiles.h"

int main() {

  Arme Ludovicator = Arme("Ludovicator", 1000000, 1, 10);
  Armure Ludotector = Armure("Ludotector", 100000, 1, 10);
  Joueurs Ludo = Joueurs("Ludo", 100, 10, 10, 10, 10, 10, 100, Ludovicator, Ludotector);
  
  Arme baton = Arme("baton", 1, 1, 1);
  Armure rien = Armure("rien", 0, 0, 0);
  Joueurs Francois = Joueurs("Francois", 500, 1, 1, 1, 1, 1, 1, baton, rien);

  Arme morsure = Arme("Dent", 1, 1, 1);
  Monstre Francou = Monstre("Francois", 500, 1, 1, 1, 1, 1, 1, Ludovicator, rien);

  cout << Francois.get_pv() << endl;

  Ludo.attaquer_Un_Autre_Personnage(Ludovicator, &Francois);

  cout << Francois.get_pv() << endl;

  vector<Personnage *> liste_personnage = {&Francou};
  Ludo.deciderAction(liste_personnage, 1);

  cout << Francou.get_pv() << endl;

  vector<Personnage *> liste_personnage_2 = {&Ludo};
  Francou.deciderAction(liste_personnage_2, 1);

  cout << "L'incroyable Ludo a : " << Ludo.get_pv() << " PV." << endl;

  return 0;
}
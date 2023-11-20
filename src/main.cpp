#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <list>

using namespace std;

#include "AllFiles.h"

int main() {

  cout << "Hello World" << "\n";

  Jeu jeu;

  jeu.readText(4);

  for (OperationToDo op: jeu.vectorToDo) {
    cout << op.operation << " " << op.pointer_1 << "\n"; 
  }

  Arme epee = Arme("Epee en fer", 50, 3, 4);
  Armure plastron = Armure("Plastron", 80, 7, 4);
  Joueurs YoMan = Joueurs("Yoyo", 100, 5, 5, 5, 5, 5, 5, epee, plastron);

  Monstre Gobelin = Monstre("Gobelin", 50, 2, 2, 2, 2, 2, 2, epee, plastron);

  vector<Personnage *> personne = {&YoMan, &Gobelin};

  jeu.startCombat(personne);

  return 0;
}
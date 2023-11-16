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

  for (OperationToDo op: jeu.vector_to_do) {
    cout << op.operation << " " << op.pointer_1 << "\n"; 
  }

  return 0;
}
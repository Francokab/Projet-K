#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <list>

//Ces includes sont présents pour cout les caractères spéciaux (types é, à, è).
//Cela ne devrait pas marcher sur un linux.
#include <cstdio>
#include <windows.h>

#pragma execution_character_set( "utf-8" )

using namespace std;

#include "AllFiles.h"

int main()
{
  //Pour les caractères spéciaux
  SetConsoleOutputCP( 65001 );

  Jeu jeu;

  jeu.start();

  return 0;
}
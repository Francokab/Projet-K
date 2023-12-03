#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <list>

//Ces includes sont présents pour cout les caractères spéciaux (types é, à, è).
//Cela ne devrait pas marcher sur un linux.
#ifdef __unix__         
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif

#ifdef OS_Windows
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )
#endif



using namespace std;

#include "AllFiles.h"

int main()
{
  #ifdef OS_Windows
  //Pour les caractères spéciaux
  SetConsoleOutputCP( 65001 );
  #endif

  Jeu jeu;

  jeu.start();

  return 0;
}
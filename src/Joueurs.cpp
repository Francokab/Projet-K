#include "joueurs.h"

using namespace std;

int Joueurs::deciderAction(){
    string choix = "";
    int choix_int = 0;
    bool exception_present = 1;
    while(exception_present) {

        //On essaye de pouvoir capter les erreurs dans l'écriture du choix des joueurs dans le terminal
        cin >> choix;
        try {
            int choix_int = stoi(choix); 
            exception_present = 0;
        } catch (exception()) {
            cout << "N'utiliser que 1 ou 2." << endl;
        }
    }

    return choix_int;

}
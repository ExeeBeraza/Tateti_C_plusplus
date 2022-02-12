//
// Created by ben on 06/02/2022.
//

#include "Score.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Score::Score() {};

int Score::guardarScore(string vecJugadas) {

    ofstream archivo;

    archivo.open("scores.txt",ios::app);

    for(int item = 0; item <= 5; item++){
        archivo << vecJugadas[item];

    }

    archivo.close();

    return 0;
};

string Score::OrdenarScore(string *vecJugadas) {

    string esMayor = " ";
    bool boolOrdeno = true;

    while (boolOrdeno != false) {
        boolOrdeno = false;
        for (int i = 0; i <= vecJugadas->length(); i++) {//(len(vec)-1){
            if (vecJugadas[i] < vecJugadas[i + 1]) {
                esMayor = vecJugadas[i];
                vecJugadas[i] = vecJugadas[i + 1];
                vecJugadas[i + 1] = esMayor;
                boolOrdeno = true;

            }
        }




    }
    return esMayor;
}

int Score::mostrarScore(string nombreUsuario, string vecJugadas) {

    cout << "Top 5 Mejores partidas" << endl;

    ifstream archivo;

    int resultado=0;

    resultado=1;

    archivo.open("scores.txt",ios::in);

    if(!archivo.fail()) {
        for (int item = 0; item <= 5; item++) {
            cout << nombreUsuario << guardarScore(vecJugadas);

        }
    }
    archivo.close();



    return resultado;


};



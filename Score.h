//
// Created by ben on 06/02/2022.
//

#ifndef JUEGO_CPP_SCORE_H
#define JUEGO_CPP_SCORE_H

#include <iostream>
#include <string>

using namespace std;

class Score {

public:
    Score();

    string OrdenarScore(string *vecJugadas);
    int guardarScore(string jugador);
    int mostrarScore(string nombreUsuario, string vecJugadas);
};


#endif //JUEGO_CPP_SCORE_H

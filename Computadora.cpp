//
// Created by ben on 26/01/2022.
//

#include "Computadora.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


Computadora::Computadora() {};

int Computadora::insertarFicha(string ficha, int casilla) {

    int resultado = 1;

    if (comprobarCasilleroLibre(casilla)) {
        tablero[casilla] = ficha;
        mostrarTablero();

        resultado = 0;

    }

    return resultado;

};

int Computadora::jugarHumano(string ficha,int casilla) {

    vecJugadas->append(to_string(casilla));

    return insertarFicha(ficha,casilla);

};

bool Computadora::esEmpate(){

    for(int i=0; i <= 9 ; i++){
        if(tablero[i] == " "){
            return false;
        }
    }
    return true;
}

bool Computadora::comprobarCasilleroLibre(int casilla) {

    bool resultado = false;

    if(tablero[casilla] == " "){
        resultado = true;

    }
    return resultado;

};

void Computadora::mostrarTablero() {

    cout << "_" << tablero[1] << "_|_" << tablero[2] << "_|_" << tablero[3] << "_" << endl;
    cout << "_" << tablero[4] << "_|_" << tablero[5] << "_|_" << tablero[6] << "_" << endl;
    cout << " " << tablero[7] << " | " << tablero[8] << " | " << tablero[9] << " " << endl;
};

bool Computadora::verificarGanador() {

    bool ganador = false;

    for(int i=1; i <= 24 ; i = i+3) {
        if (vecJugadas[i] == vecJugPos[i]  && vecJugadas[i+1] == vecJugPos[i+1] && vecJugadas[i + 2] == vecJugPos[i + 2] && vecJugadas[i] == " ") {
            ganador = true;
        }
    }

    return ganador;



};

bool Computadora::verificarGanador(string persona) {

    bool ganador = false;

    for(int i=1; i <= 24 ; i = 1+3) {
        if (vecJugadas[i] == vecJugPos[i]  && vecJugadas[i+1] == vecJugPos[i+1] && vecJugadas[i + 2] == vecJugPos[i + 2] && vecJugadas[i] == persona) {
            ganador = true;
        }
    }

    return ganador;

};

int Computadora::minimax(pair<int,string> posicion ,int rama, bool indicadorMaximo) {

    // Para avanzar checkea que este libre
    if (posicion.second == " "){
        cout << "La posicion: " << posicion.first << endl;

        // Valido el parametro indicador para poner "X" o "0"
        if (indicadorMaximo){ posicion.second = "0";} else {posicion.second = "X";}

        // Paso recursivo
        minimax({posicion.first + 1,posicion.second},rama+1,!indicadorMaximo);

        // Reseteo la posicion
        posicion.second = " ";
    }
    return 0;
}

int Computadora::jugarComputadora() {
    cout << "Entro" << endl;

    mejorPuntaje = -1000;

    for(pair<int,string> element : tablero){
        if(element.second == " "){
            element.second = "0";
            //cout << "Procediendo con el minmax"<< endl;
            // Hay que revisar esta funcion
            //puntaje = minimax(0,false);
            //cout << "El resultado del minimax: " << puntaje << endl;

            element.second = " ";
            minimax(element,0,true);
            //if(puntaje > mejorPuntaje){
            //    puntaje = mejorPuntaje;
            mejorMovimiento = element.first;
            //}
        }

    }

    cout << "LLegue"<<endl;
    return insertarFicha("0", mejorMovimiento);
}


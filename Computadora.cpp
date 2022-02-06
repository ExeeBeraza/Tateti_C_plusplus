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

    for(int i=0; i <= 23 ; i = i+3) {
        if (vecJugadas[i] == vecJugPos[i]  && vecJugadas[i+1] == vecJugPos[i+1] && vecJugadas[i + 2] == vecJugPos[i + 2] && vecJugadas[i] == " ") {
            ganador = true;
        }
    }

    return ganador;



};

bool Computadora::verificarGanador(string persona) {

    bool ganador = false;

    for(int i=0; i <= 23 ; i = 1+3) {
        if (vecJugadas[i] == vecJugPos[i]  && vecJugadas[i+1] == vecJugPos[i+1] && vecJugadas[i + 2] == vecJugPos[i + 2] && vecJugadas[i] == persona) {
            ganador = true;
        }
    }

    return ganador;

};

int Computadora::minimax(unordered_map<int,string> tabs, int rama, bool indicadorMaximo) {
    // TODO: Verificacion de resultados

    if(indicadorMaximo){
        mejorPuntaje = -1000;
        for(pair<int,string> element : tabs){
            if (element.second == " "){
                element.second = "0";
                puntaje = minimax({{element.first,element.second}},rama+1,false);
                element.second = " ";
                if(puntaje > mejorPuntaje)
                    mejorPuntaje = puntaje;
            }
        }
    }else{
        mejorPuntaje = 1000;
        for(pair<int, string>element : tabs){
            if (element.second == " "){
                element.second = "X";
                puntaje = minimax({{element.first,element.second}},rama+1, true);
                element.second = " ";
                if(puntaje < mejorPuntaje)
                    mejorPuntaje = puntaje;
            }
        }
    }
    return mejorPuntaje;
}

int Computadora::jugarComputadora() {
    mejorPuntaje = -1000;
    mejorMovimiento = 0;

    for(pair<int,string> element : tablero){
        if(element.second == " "){
            element.second = "0";
            //cout << "Procediendo con el minmax"<< endl;
            // Hay que revisar esta funcion
            puntaje = minimax({{element.first,element.second}},0,false);
            //cout << "El resultado del minimax: " << puntaje << endl;

            element.second = " ";

            if(puntaje > mejorPuntaje){
                mejorPuntaje = puntaje;
                mejorMovimiento = element.first;
            }
        }

    }

    cout << "LLegue: " << mejorMovimiento <<endl;
    return insertarFicha("0", mejorMovimiento);
}


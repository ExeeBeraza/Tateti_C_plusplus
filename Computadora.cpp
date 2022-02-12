//
// Created by ben on 26/01/2022.
//

#include "Computadora.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>

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
    vecJugadas[casilla] += casilla;  //vecJugadas//vecJugadas->append(to_string(casilla));
    return insertarFicha(ficha,casilla); //retorna como resultado la función que insertará la ficha dentro del tablero pasandole como parametro, "X" que será la ficha del jugador y el numero de la casilla que eligió el jugador
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

    bool quienEsGanador = false;

    for(int item = 1; item <= 23; item+3){
        if(vecJugadas[item] == vecJugPos[item]  && vecJugadas[item+1] == vecJugPos[item+1] && vecJugadas[item + 2] == vecJugPos[item + 2] && vecJugadas[item] == " " ){
            quienEsGanador = true;
        }
    }

    return quienEsGanador;

};

int Computadora::minimax(unordered_map<int,string> tabs, int rama, bool indicadorMaximo) {

    cout << "Minimax"<<endl;

    string ficha;

    // TODO: Verificacion de resultados

    // TODO: Repite la misma idea implementada que en la función jugarComputadora, por esto es que ambas están relacionadas entre sí

    // Verifico si el indicador me permite seguir profundizando en las ramas

    if (indicadorMaximo){
        mejorPuntaje=-1000;
        ficha = "0";
    }else{
        mejorPuntaje=1000;
        ficha="X";
    }

    for(pair<int,string> element : tabs){
        if(element.second == " "){
            element.second = ficha;
            puntaje = minimax({{element.first,element.second}},rama+1,!indicadorMaximo);
            element.second = " ";
        }
    }

    mejorPuntaje = puntaje;

    return puntaje;
}

int Computadora::jugarComputadora() {
    cout << "Jugando la computadora" << endl;
    // Establesco el mejor puntaje por default (se
    mejorPuntaje = -1000;

    // Recorro el tablero
    for(pair<int,string> element : tablero){
        cout << "El elemento: " << element.first << " :: " << element.second << endl;

        // ¿El casillero esta vacio?
        if(element.second == " "){
            // Ocupo el lugar (momentaneamente)
            element.second = "0";
            // Asigno el puntaje

            cout << "#1" << endl;
            puntaje = minimax({{element.first,element.second}},0,false);
            element.second = " ";

            if(puntaje > mejorPuntaje){
                mejorPuntaje = puntaje;

                // Indico que el mejor movimiento es el numero de casillero retornado mas arriba
                mejorMovimiento = element.first;
            }
        }

    }

    // Ocupo el lugar (definitivamente)
    cout << "El mejor movimiento: " << mejorMovimiento << endl;
    return insertarFicha("0", mejorMovimiento);
}


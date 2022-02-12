//
// Created by ben on 26/01/2022.
//

#include "Computadora.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>

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

    vecJugadas.sort();
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

    for(int item = 1; i <= 23; i+3){
        if(vecJugadas[item] == vecJugPos[item]  && vecJugadas[item+1] == vecJugPos[item+1] && vecJugadas[item + 2] == vecJugPos[item + 2] && vecJugadas[item] == " " ){
            quienEsGanador = true;
        }
    }

    return quienEsGanador;

};

int Computadora::minimax(unordered_map<int,string> tabs, int rama, bool indicadorMaximo) {
    // TODO: Verificacion de resultados

    // TODO: Repite la misma idea implementada que en la función jugarComputadora, por esto es que ambas están relacionadas entre sí

    // Verifico si el indicador me permite seguir profundizando en las ramas

    unordered_map<int, string>::iterator it = tabs.begin();
    /*
    while(it != tabs.end()) {
        if (it->second == " " && indicadorMaximo == true) {
            mejorPuntaje = -1000;
            // En caso afirmativo lo marco y asigno puntaje diciendole que no profundice la rama
            it->second = "0";
            puntaje = minimax({{it->first, it->second}}, rama + 1, false);
            // Reseteo el valor de la posicion
            it->second = " ";
            // Verifico que el puntaje sea menor al puntaje mayor
            if (puntaje > mejorPuntaje) {
                mejorPuntaje = puntaje;
            }
        }
            //mismo que lo anterior exceptuando algunas opuestas y debe ser así
        else if (it->second == " " && indicadorMaximo == false) {
            mejorPuntaje = 1000;
            it->second = "X";
            puntaje = minimax({{it->first, it->second}}, rama + 1, true);
            it->second = " ";
            if (puntaje < mejorPuntaje){
                mejorPuntaje = puntaje;
            }

        }
    }

    return mejorPuntaje;
   */

    //Según el valor de indicadorMaximo que le pasaré por defecto en la función jugarComputadora hará una cosa u otra
    if(indicadorMaximo){
        mejorPuntaje = -1000; //Le asigno a la variable mejorPuntaje un número por default para luego ser comparda con la variable que retornará puntaje(que retornará) la función minimax, según el valor el valor de indicadorMaximo
        // Recorro todos los casilleros del tablero mientras que puntaje sea distinto de 0
        for(pair<int,string> element : tabs){
            // Verifico si esta vacio
            if (element.second == " "){
                // En caso afirmativo lo marco y asigno puntaje diciendole que no profundice la rama
                element.second = "0";
                puntaje = minimax({{element.first,element.second}},rama+1,false);
                // Reseteo el valor de la posicion
                element.second = " ";
                // Verifico que el puntaje sea menor al puntaje mayor
                if(puntaje > mejorPuntaje) {
                    mejorPuntaje = puntaje;
                }
            }
        }
    }//mismo que lo anterior exceptuando algunas opuestas y debe ser así
    else{
        mejorPuntaje = 1000; //Le asigno a la variable mejorPuntaje un número por default para luego ser comparda con la variable que retornará puntaje(que retornará) la función minimax, según el valor el valor de indicadorMaximo
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
    return puntaje; //retornará el valor que final según como se fueron dando lo anterior

}

int Computadora::jugarComputadora() {

    mejorPuntaje = -1000; //Le asigno a la variable mejorPuntaje un número por default para luego ser comparada con la variable que retornará puntaje(que retornará) la función minimax

    for(pair<int,string> element : tablero){  //recore el tablero/definido como diccionario
        //preguntará por el segunto elemento del diccionario es decir, la contine los valores String..ya que element.first contiene los Integer que serán el indices
        if(element.second == " "){
            //...por defecto si la primera poscion esta vacía inserta la ficha en este mismo lugar
            element.second = "0";
            //cout << "Procediendo con el minmax"<< endl;
            //llamando a la función minimax por medio la variable puntaje que adoptará el valor de dicha función
            puntaje = minimax({{element.first,element.second}},0,false);
            //cout << "El resultado del minimax: " << puntaje << endl;
            element.second = " ";

            if(puntaje > mejorPuntaje){   // preguntará en cada ciclo, por ambas variables 'importantes' si son iguales, idea implementada por lo que se llama poda-alfa
                mejorPuntaje = puntaje;     // igualo ambos valores como actualización del punteje general
                mejorMovimiento = element.first;  //le asigna el primer valor del tablero osea el integer, en la que la vuelta donde llegó que si se cumple la condicón anterior
            }
        }

    }

    return insertarFicha("0", mejorMovimiento); //retorna como resultado la función que insertará la ficha dentro del tablero pasandole como parametro, "0" que será la ficha de la computadora y mejormovimiento que tendrá como valor aquel indice del diccionario tablero
}


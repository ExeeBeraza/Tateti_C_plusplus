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

int Computadora::minimax(int rama, bool indicadorMaximo) {

    /*
    // Resultados de partidas
    cout << "Verificando resultados..."<< endl;

    if(verificarGanador("0")){
        return 100;
    }else if(verificarGanador("X")){
        return -100;
    }else if(esEmpate()){
        return 0;
    }
    */

    auto it = tablero.begin();


    // Verifico si el indicador me permite seguir profundizando en las ramas
    if (indicadorMaximo){
        mejorPuntaje = -10000;
        // Recorro todos los casilleros del tablero mientras que puntaje sea distinto de 0
        while (it->second == " " ){
            cout << "Posicion " << it->first << it->second << endl;
            // Verifico si esta vacio
            //if (it->second == " ") {
            // En caso afirmativo lo marco y asigno puntaje diciendole que no profundice la rama
            //it->second = "0";
            //puntaje = minimax(rama + 1, false);
            // Reseteo el valor de la posicion
            //it->second = " ";
            // Verifico que el puntaje sea menor al puntaje mayor
            /*
            if (puntaje > mejorPuntaje) {
                puntaje = mejorPuntaje;
            }
            */
            //}
            it++;
        }
        //mismo que lo anterior exceptuando algunas opuestas y debe ser así

    }//else{
    //mejorPuntaje = 10000;
    // Recorro todos los casilleros del tablero mientras que puntaje sea distinto de 0
    //while (it->second == " " ) {
    //cout << "Posicion " << it->first << it->second << endl;
    // Verifico si esta vacio
    //if (it->second == " ") {

    // En caso afirmativo lo marco y asigno puntaje diciendole que no profundice la rama
    //it->second = "X";
    //puntaje = minimax(rama + 1, true);
    // Reseteo el valor de la posicion
    //it->second = " ";
    // Verifico que el puntaje sea menor al puntaje mayor

    //if (puntaje < mejorPuntaje) {
    //    puntaje = mejorPuntaje;
    // }

    //}
    // it++;
    // }
    //}


    /*
    }else{
        mejorPuntaje = 10000;
        for(pair<int,string> elemento : tablero){
            if(elemento.second == " "){
                elemento.second = "X";
                puntaje = minimax(rama+1, true);
                elemento.second = " ";
                if(puntaje < mejorPuntaje) {
                    puntaje = mejorPuntaje;
                }
            }
        }
    }
    */
    //cout << "Retornando el puntaje... " << puntaje << endl;
    return puntaje;
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
            minimax(0,true);
            //if(puntaje > mejorPuntaje){
            //    puntaje = mejorPuntaje;
            mejorMovimiento = element.first;
            //}
        }

    }

    cout << "LLegue"<<endl;
    return insertarFicha("0", mejorMovimiento);
}


//
// Created by ben on 26/01/2022.
//

#ifndef MAIN_CPP_JUEGO_H
#define MAIN_CPP_JUEGO_H

#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

class Computadora {

public:
    /*
     * varialbes
     */
    int mejorPuntaje;     //va a adoptar hasta el momento de la partida, en detalles lo quu sería la iteración el mejor puntaje hasta el momento, utilizado para uso exclusivo del algortimo minmax en uso de la IA
    int mejorMovimiento;  //va a adoptar hasta el momento de la partida, en detalles lo quu sería la iteración el mejor movimiento que seria conveniente hasta el momento, utilizado para uso exclusivo del algortimo minmax en uso de la IA
    int puntaje;   //va a doptar hasta el momento de la partida, en detalles lo quu sería la iteración el mejor puntaje hasta el momento, utilizado para uso exclusivo del algortimo minmax en uso de la IA

    /*
    * vectores
    */
    string vecJugadas[10] = {};
    unordered_map<int,string>tablero = {
            {1, " "},
            {2, " "},
            {3, " "},
            {4, " "},
            {5, " "},
            {6, " "},
            {7, " "},
            {8, " "},
            {9, " "},
            {10, " "}
    };
    string vecJugPos[24] = {"1", "5", "9", "3", "5", "7", "1", "4", "7","2", "5", "8", "3", "6", "9", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    Computadora();

    int insertarFicha(string ficha, int casilla);
    bool comprobarCasilleroLibre(int casilla);
    void mostrarTablero();
    int jugarComputadora();
    int jugarHumano(string ficha,int casilla);
    bool verificarGanador();
    bool verificarGanador(string persona);
    bool esEmpate();


//private:
    int minimax(pair<int,string> tabs, int rama, bool indicadorMaximo);
};



#endif //MAIN_CPP_JUEGO_H

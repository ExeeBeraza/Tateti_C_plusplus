//
// Created by ben on 18/01/2022.
//


#include "Jugador.h"
#include "Computadora.h"
#include "Computadora.cpp"
#include "DatoSesion.cpp"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){

    Computadora oComputadora;
    Jugador oJugador;
    DatoSesion datoSesion;

    int modoJuego, opIngreso, intentos = 0;
    bool verificador = true;

    /*
    cout << "────────────────────────────────────────────────────────────────" << endl;
    cout << "               1) - Iniciar Sesión                              " << endl;
    cout << "               2) - Registrarse                                 " << endl;
    cout << "────────────────────────────────────────────────────────────────" << endl;
    cout << "Eliga una de las opciones: ";

    cin >> opIngreso;

    if(opIngreso==1){

        cout<<"Nombr e de usuario: ";
        cin >> oJugador.nombre_usuario;

        cout<<"contraseña: ";
        cin >> oJugador.password;

        if(datoSesion.guardarDatos(oJugador.nombre,oJugador.nombre_usuario,oJugador.password)==0){
            cout<<"¡Datos ingresados incorrectamente!"<<endl;

        };
    }
    else if(opIngreso==2){

        cout << "Nombre: ";
        cin >> oJugador.nombre;

        cout<<"Nombre de usuario: ";
        cin >> oJugador.nombre_usuario;

        cout << "contraseña: ";
        cin >> oJugador.password;


        if(datoSesion.buscarDatos(oJugador.nombre_usuario,oJugador.password)==2){
            cout<<"Encontrado!"<<endl;
        }
        else if(datoSesion.buscarDatos(oJugador.nombre_usuario,oJugador.password)==1){
            cout<<"NO Encontrado!"<<endl;
        }
        else{
            cout<<"Datos incorrectos"<<endl;

        };

    }
    */
    cout << "────────────────────────────────────────────────────────────────" << endl;
    cout << "               1 --> 1vs1                                       " << endl;
    cout << "               2 --> vs Computadora                             " << endl;
    cout << "────────────────────────────────────────────────────────────────" << endl;

    cin >> modoJuego;

    cout << "_" << "1" << "_|_" << "2" << "_|_" << "3" << "_" << endl;
    cout << "_" << "4" << "_|_" << "5" << "_|_" << "6" << "_" << endl;
    cout << " " << "7" << " | " << "8" << " | " << "9" << " " << endl;


    if(modoJuego== 1) {
        while (verificador == true) {

            /*Turno en X*/
            cout << "Turno X ";
            cin >> oJugador.numeroCasillero;
            oComputadora.jugarHumano("X",oJugador.numeroCasillero);
            //system("clear");

            /*Turno en 0*/
            cout << "Turno 0 ";
            cin >> oJugador.numeroCasillero;
            oComputadora.jugarHumano("0",oJugador.numeroCasillero);
            //system("clear");

            if(oComputadora.esEmpate()){
                cout << "¡EMPATE!";
                verificador = false;
            }
        }
    }
    else if(modoJuego ==2){
        while (verificador == true) {
            /*Turno en X*/
            cout << "Turno X" << endl;
            cin >> oJugador.numeroCasillero;
            oComputadora.jugarHumano("X",oJugador.numeroCasillero);
            //system("clear");

            /*Turno en 0*/
            cout << "Turno 0" << endl;
            oComputadora.jugarComputadora();
            //system("clear");

        }
    }

    return 0;
}






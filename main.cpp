//
// Created by ben on 18/01/2022.
//


#include "Jugador.h"
#include "Computadora.h"
#include "DatoSesion.h"
#include "Computadora.cpp"
#include "DatoSesion.cpp"
#include "Score.cpp"
#include <iostream>

using namespace std;

int main(){

    /* Abstraciones de clases*/
    Computadora computadora;
    Jugador jugador;
    DatoSesion datoSesion;
    Score score;

    /* variables locales, contadores, opciones para el menu ...etc */
    int modoJuego, opIngreso, intentos = 0;
    bool verificador = true;

    /*
    cout << "────────────────────────────────────────────────────────────────" << endl;
    cout << "               1) - Iniciar Sesión                              " << endl;
    cout << "               2) - Registrarse                                 " << endl;
    cout << "────────────────────────────────────────────────────────────────" << endl;
    cout << "Eliga una de las opciones: ";

    cin >> opIngreso;
    while(intentos <= 10){
         if(opIngreso==1){

            cout<<"Nombre de usuario: ";
            cin >> jugador.nombre_usuario;

            cout<<"contraseña: ";
            cin >> jugador.password;

            if(datoSesion.guardarDatos(jugador.nombre,jugador.nombre_usuario,jugador.password)==0){
                cout<<"¡Datos ingresados incorrectamente!"<<endl;
                intentos ++;
            };
         }
        else if(opIngreso==2){

            cout << "Nombre: ";
            cin >> jugador.nombre;

            cout<<"Nombre de usuario: ";
            cin >> jugador.nombre_usuario;

            cout << "contraseña: ";
            cin >> jugador.password;

            if(datoSesion.buscarDatos(jugador.nombre_usuario,jugador.password)==2){
                cout<<"Encontrado!"<<endl;
            }
            else if(datoSesion.buscarDatos(jugador.nombre_usuario,jugador.password)==1){
                cout<<"NO Encontrado!"<<endl;
            }
            else{
                cout<<"Datos incorrectos"<<endl;
        };
    }









     }

    */
    cout << "────────────────────────────────────────────────────────────────" << endl;
    cout << "               1 --> 1vs1                                       " << endl;
    cout << "               2 --> vs Computadora                             " << endl;
    cout << "────────────────────────────────────────────────────────────────" << endl;
    cout << "Eliga una de las opciones: ";

    cin >> modoJuego;

    cout << "_" << "1" << "_|_" << "2" << "_|_" << "3" << "_" << endl;
    cout << "_" << "4" << "_|_" << "5" << "_|_" << "6" << "_" << endl;
    cout << " " << "7" << " | " << "8" << " | " << "9" << " " << endl;


    if(modoJuego== 1) {
        while (verificador == true) {

            /*Turno en X*/
            cout << "Turno X ";
            cin >> jugador.numeroCasillero;
            computadora.jugarHumano("X",jugador.numeroCasillero);
            //system("clear");

            /*Turno en 0*/
            cout << "Turno 0 ";
            cin >> jugador.numeroCasillero;
            computadora.jugarHumano("0",jugador.numeroCasillero);

            if(computadora.verificarGanador()==true) {
                cout << "¡X GANADOR!";
                verificador = false;
            }
            else if(computadora.verificarGanador()== false){
                cout << "¡0 GANADOR!";
                verificador = false;
            }

            else if(computadora.esEmpate()){
                cout << "¡EMPATE!";
                verificador = false;
            }
        }
    }
    else if(modoJuego ==2){
        while (verificador) {
            /*Turno en X*/
            cout << "Turno X" << endl;
            cin >> jugador.numeroCasillero;
            computadora.jugarHumano("X",jugador.numeroCasillero);

            /*Turno en 0*/
            cout << "Turno 0" << endl;
            computadora.jugarComputadora();
            cout << "Finalizando turno" << endl;

            score.guardarScore("0");
            verificador = !verificador;//computadora.verificarGanador();
        }
    }

    return 0;
}


/*#include <cstdlib>
#inculde <iostream>

using namespace std;

int main(int argc, char** argv){

    int numerocordena; //valor de la variable

    //&N es el valor de la

    //auto toma de numerocordenada su dirección de memoria y es un puntero
    int *auto = &N;


    //Asignó a una varible puntero la dirección de una variable no puntero
    numerocordenada = *Z;
    Z = &N;
    // A variable puntero puede asignarse el contenido de otra variable puntero si son compatibles (ambos puntero apuntan al mismo tipo de dato).  --> este caso int

    int *Y,*X;
    Y=X


    // A puntero es posible asignarle el valor NULL (el puntero no apunta a dirección de memoria alguna).

    int *Y;
    Y = NULL;


    //Es posible sumar o restar una cantidad entera a una varialbe puntero. La nueva dirección de memoria obtenida difiere de la inicial en una cantidad de bytes dada por el tipo de dato del apuntado.

    bool *dato;

    cout << dato << endl;			0x23cc8c

    dato += 1;

    cout << dato << endl;			0x23cc8d



    Es posbile comparar dos variables puntero si estas son compatibles (apunta a datos de igual tipo)

    u==v        u!=v       u==NULL          u<v           u>= v

    Es posbile operar los datos apuntados a través de la notación de punteros:

    *p < *q            *p++         (*q)    --         *r = 23.5

*/

/*Punteros y apilamiento*/



/*
int *pila;
int dato;

dato = 1;
*pila = dato;   //cargo un valor 1 en la pila

dato = 3;
pila += 1;         // al incrementar un int, se avanzan 4 bytes.
*pila = dato;      // cargo un valor 3 en la pila


dato = 5;
pila += 1;
*pila = dato;

for(int i=0;i<3;i++){
cout << "Posición: " << &pila << ", Dato: " << *pila << endl;
pila--;   //Mediante un ciclo, se retrocede de a 4 bytes, para mostrar el "dato" de cada 				apuntamiento en memoria
};



return 0;
}
*/



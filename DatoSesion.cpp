//
// Created by ben on 01/02/2022.
//

#include "DatoSesion.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int DatoSesion::guardarDatos(string nombre, string nombre_usuario, string password){

    ofstream archivo;

    int resultado=0;

    if(validarDatos(nombre_usuario, password)==true){

        archivo.open("registros_usuarios.txt",ios::app);

        archivo << nombre << nombre_usuario << password << endl;

        archivo.close();
        resultado = 1;
    };

    return resultado;
}

int DatoSesion::buscarDatos(string nombre_usuario, string password){

    ifstream archivo;

    int resultado=0;

    string linea;
    string busca;

    if(validarDatos(nombre_usuario,password)==true){

        resultado=1;

        archivo.open("registros_usuarios.txt",ios::in);

        if(!archivo.fail()){
            while(!archivo.eof()){
                getline(archivo,linea);

                if(linea==busca){

                    resultado=2;
                    break;
                };
            };
        };

        archivo.close();

    };

    return resultado;

};


bool DatoSesion::validarDatos(string nombre_usuario, string password){

    bool resultado=false;

    if(nombre_usuario.length()>=3 && nombre_usuario.length()<=10){

        resultado=true;
    };

    return resultado;


}
//
// Created by ben on 01/02/2022.
//

#ifndef JUEGO_CPP_DATOSESION_H
#define JUEGO_CPP_DATOSESION_H

#include <iostream>
#include <string>

class DatoSesion {

public:
    int guardarDatos(string nombre, string nombre_usuario, string password);
    int buscarDatos(string nombre_usuario, string password);
    bool validarDatos(string nombre_usuario, string password);

};


#endif //JUEGO_CPP_DATOSESION_H

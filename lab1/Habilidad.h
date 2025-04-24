#ifndef HABILIDAD_H
#define HABILIDAD_H
#include <iostream>
using namespace std;
struct Habilidad
{
    string nombre;
    string tipo;
    Habilidad * siguiente;

    Habilidad(string nombreP, string tipoP){
        nombre=nombreP;
        tipo=tipoP;
        siguiente=nullptr;
    }
};
#endif


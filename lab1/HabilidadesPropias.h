#ifndef HABILIDADESPROPIAS_H
#define HABILIDADESPROPIAS_H
#include <iostream>
#include "Habilidad.h"
using namespace std;
struct HabilidadesPropias
{
    HabilidadesPropias * siguiente;
    Habilidad * habilidad;

    HabilidadesPropias(Habilidad * Phabilidad){
        habilidad = Phabilidad;
        siguiente=nullptr;
    }

    string toString() {
        return "Habilidad: " + habilidad->nombre;
    }
};
#endif
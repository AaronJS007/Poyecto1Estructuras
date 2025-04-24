#ifndef GENEROMUSICAL_H
#define GENEROMUSICAL_H
#include <iostream>
using namespace std;

struct generoMusical{
    int IdGeneroMusical;
    string nombre, descripcion;
    generoMusical * siguienteElemento;
    generoMusical * anteriorElemento;

    generoMusical(int pId, string pNombre, string pDescripcion){
        IdGeneroMusical=pId;
        nombre=pNombre;
        descripcion=pDescripcion;
        siguienteElemento=nullptr;
        anteriorElemento=nullptr;
    }
    ~generoMusical();

};


#endif
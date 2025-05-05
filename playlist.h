#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
using namespace std;
#include "listaCanciones.h"

struct playlist{
    int id;
    string nombre,creador;
    string fecha;
    listaCanciones * lstCanciones;
    playlist * siguienteElemento;

    playlist(int pId, string pNombre, string pCreador, string pFecha){
        id=pId;
        nombre=pNombre;
        creador=pCreador;
        fecha = pFecha;
        lstCanciones = new listaCanciones();
        siguienteElemento=nullptr;
    }
    ~playlist();
};


#endif
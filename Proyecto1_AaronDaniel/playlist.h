#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
using namespace std;

struct playlist{
    int id;
    string nombre,creador;
    //date fecha
    //lstCanciones
    playlist * siguienteElemento;

    playlist(int pId, string pNombre, string pCreador){
        id=pId;
        nombre=pNombre;
        creador=pCreador;
        //fecha
        //lstCanciones
        siguienteElemento=nullptr;
    }
    ~playlist();
};


#endif
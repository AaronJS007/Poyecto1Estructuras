#ifndef ARTISTA_H
#define ARTISTA_H
#include <iostream>
using namespace std;
#include"listaAlbumes.h"
#include"listaCanciones.h"

struct artista{
    int ID,selloDiscografico;
    string nombreArtistico, nombreReal, pais;
    listaCanciones * lstCanciones;
    listaAlbumes * lstAlbumes;
    artista * siguienteElemento;
    artista * anteriorElemento;

    artista(int pId,string pNombreArtistico, string pNombreReal, string pPais, int pSelloDiscografico){
        ID=pId;
        nombreArtistico=pNombreArtistico;
        nombreReal=pNombreReal;
        pais=pPais;
        selloDiscografico=pSelloDiscografico;
        lstCanciones = new listaCanciones();
        lstAlbumes = new listaAlbumes();
        siguienteElemento=nullptr;
        anteriorElemento=nullptr;
    }
    ~artista(){
        delete lstCanciones;
        delete lstAlbumes;
    };

};


#endif
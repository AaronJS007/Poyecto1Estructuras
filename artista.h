#ifndef ARTISTA_H
#define ARTISTA_H
#include <iostream>
using namespace std;

struct artista{
    int ID,selloDiscografico;
    string nombreArtistico, nombreReal, pais;
    //lista album
    //lista canciones
    artista * siguienteElemento;
    artista * anteriorElemento;

    artista(int pId,string pNombreArtistico, string pNombreReal, string pPais, int pSelloDiscografico){
        ID=pId;
        nombreArtistico=pNombreArtistico;
        nombreReal=pNombreReal;
        pais=pPais;
        selloDiscografico=pSelloDiscografico;
        //lista albumes
        //lista canciones
        siguienteElemento=nullptr;
        anteriorElemento=nullptr;
    }
    ~artista();

};


#endif
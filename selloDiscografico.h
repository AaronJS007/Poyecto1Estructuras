#ifndef SELLODISCOGRAFICO_H
#define SELLODISCOGRAFICO_H
#include <iostream>
using namespace std;
#include"listaArtistas.h"

struct selloDiscografico{
    int id,annoFundacion;
    string nombre,pais;
    listaArtistas * lstArtistas;
    selloDiscografico * siguienteElemento;
    selloDiscografico * anteriorElemento;

    selloDiscografico(int pId, string pNombre, string pPais,int pAnno){
        id=pId;
        nombre=pNombre;
        pais=pPais;
        annoFundacion=pAnno;
        lstArtistas = new listaArtistas();
        siguienteElemento=nullptr;
        anteriorElemento=nullptr;
    }
    ~selloDiscografico(){
        delete lstArtistas;
    };
};


#endif
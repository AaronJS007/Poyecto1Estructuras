#ifndef SELLODISCOGRAFICO_H
#define SELLODISCOGRAFICO_H
#include <iostream>
using namespace std;

struct selloDiscografico{
    int id,annoFunfacion;
    string nombre,pais;
    //lstArtistas
    selloDiscografico * siguienteElemento;
    selloDiscografico * anteriorElemento;

    selloDiscografico(int pId, string pNombre, string pPais,int pAnno){
        id=pId;
        nombre=pNombre;
        pais=pPais;
        annoFunfacion=pAnno;
        //lstArtistas
        siguienteElemento=nullptr;
        anteriorElemento=nullptr;
    }
    ~selloDiscografico();
};


#endif
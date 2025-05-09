#ifndef CANCION_H
#define CANCION_H
#include <iostream>
using namespace std;

struct cancion{
    int ID,anno, idAlbum, idArtista;
    float duracion;
    string titulo;
    cancion * siguienteElemento;

    cancion(int pId,string pTitulo, float pDuracion, int pAnno, int pIdAlbum, int pIdArtista){
        ID=pId;
        titulo=pTitulo;
        duracion=pDuracion;
        anno=pAnno;
        idAlbum=pIdAlbum;
        idArtista=pIdArtista;
        siguienteElemento=nullptr;
    }
    ~cancion();

};


#endif
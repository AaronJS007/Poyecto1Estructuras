#ifndef ALBUM_H
#define ALBUM_H
#include <iostream>
using namespace std;

struct album{
    int IDAlbum, anno, numeroCanciones, idAlbum, idArtista;
    string titulo;
    album * siguienteElemento;

    album(int pIdAlbum,string pTitulo, int pAnno, int pNumeroCanciones, int pIdArtista){
        IDAlbum=pIdAlbum;
        titulo=pTitulo;
        anno=pAnno;
        numeroCanciones=pNumeroCanciones;
        idArtista=pIdArtista;
        //lst canciones
        siguienteElemento=nullptr;
    }
    ~album(); 

}; 


#endif
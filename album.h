#ifndef ALBUM_H
#define ALBUM_H
#include <iostream>
using namespace std;
#include "listaCanciones.h"

struct album
{
    int IDAlbum, anno, numeroCanciones, idAlbum, idArtista;
    string titulo;
    listaCanciones *lstCanciones;
    album *siguienteElemento;

    album(int pIdAlbum, string pTitulo, int pAnno, int pNumeroCanciones, int pIdArtista)
    {
        IDAlbum = pIdAlbum;
        titulo = pTitulo;
        anno = pAnno;
        numeroCanciones = pNumeroCanciones;
        idArtista = pIdArtista;
        lstCanciones = new listaCanciones();
        siguienteElemento = nullptr;
    }
    ~album();
};

#endif
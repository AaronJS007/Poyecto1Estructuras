#ifndef LISTAALBUMES_H
#define LISTAALBUMES_H
#include <iostream>
using namespace std;
#include "album.h"
struct listaAlbumes
{
    album *primerElemento;
    listaAlbumes()
    {
        primerElemento = nullptr;
    }
    ~listaAlbumes()
    {
        album *temp;
        while (primerElemento)
        {
            temp = primerElemento;
            primerElemento = primerElemento->siguienteElemento;
            delete temp;
        }
    }

    bool incercionInicio(int ID,string titulo,int anno, int numeroCanciones, int IDArtista)
    {
        try
        {
            album *Nuevo = new album(ID, titulo, anno, numeroCanciones, IDArtista);
            if (primerElemento == nullptr)
            {
                primerElemento = Nuevo;
            }
            else
            {
                album *temp = primerElemento;
                while (temp->siguienteElemento != nullptr)
                {
                    if (temp->idAlbum == Nuevo->idAlbum)
                    {
                        delete Nuevo;
                        return false;
                    }
                    temp = temp->siguienteElemento;
                }
                temp->siguienteElemento = Nuevo;
            }
            return true;
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
            return false;
        }
    }

    bool modificar(int ID,string titulo,int anno, int numeroCanciones, int IDArtista)
    {
        album *temp = primerElemento;
        while (temp)
        {
            if (temp->idAlbum == ID)
            {
                temp->titulo = titulo;
                temp->anno = anno;
                temp->numeroCanciones=numeroCanciones;
                temp->lstCanciones;
                temp->idArtista = IDArtista;
                return true;
            }
            temp = temp->siguienteElemento;
        }
        return false;
    }

    bool eliminarPokemon(int id)
    {
        if (primerElemento == nullptr)
        {
            return false;
        }
        cancion *temp = primerElemento;

        if (primerElemento->ID == id)
        {
            primerElemento = primerElemento->siguienteElemento;
            delete temp;
            return true;
        }

        while (temp->siguienteElemento != nullptr)
        {
            if (temp->siguienteElemento->ID == id)
            {
                cancion *eliminar = temp->siguienteElemento;
                temp->siguienteElemento = eliminar->siguienteElemento;
                delete eliminar;
                return true;
            }
            temp = temp->siguienteElemento;
        }

        return false;
    }
};

#endif


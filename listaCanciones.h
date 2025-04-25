#ifndef LISTACANCIONES_H
#define LISTACANCIONES_H
#include <iostream>
using namespace std;
#include "cancion.h"
struct listaCanciones
{
    cancion *primerElemento;
    listaCanciones()
    {
        primerElemento = nullptr;
    }
    ~listaCanciones()
    {
        cancion *temp;
        while (primerElemento)
        {
            temp = primerElemento;
            primerElemento = primerElemento->siguienteElemento;
            delete temp;
        }
    }

    bool incercionInicio(int ID, string titulo, int duracion, int año, int idAlbum, int idArtista)
    {
        try
        {
            cancion *Nuevo = new cancion(ID, titulo, duracion, año, idAlbum, idArtista);
            if (primerElemento == nullptr)
            {
                primerElemento = Nuevo;
            }
            else
            {
                cancion *temp = primerElemento;
                while (temp->siguienteElemento != nullptr)
                {
                    if (temp->ID == Nuevo->ID)
                    {
                        delete Nuevo;
                        return false;
                    }
                    temp = temp->siguienteElemento;
                }
                Nuevo->siguienteElemento=primerElemento;
                primerElemento=Nuevo;
            }
            return true;
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
            return false;
        }
    }

    bool modificar(int ID, string nuevoTitulo, int nuevaDuracion, int nuevoAnno, int nuevoIdAlbum, int nuevoIdArtista)
    {
        cancion *temp = primerElemento;
        while (temp)
        {
            if (temp->ID == ID)
            {
                temp->titulo = nuevoTitulo;
                temp->duracion = nuevaDuracion;
                temp->anno = nuevoAnno;
                temp->idAlbum = nuevoIdAlbum;
                temp->idArtista = nuevoIdArtista;
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

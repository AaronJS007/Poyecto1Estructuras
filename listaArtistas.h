#ifndef LISTAARTISTA_H
#define LISTAARTISTA_H
#include <iostream>
using namespace std;
#include "artista.h"

struct listaArtistas
{
    artista *primerElemento;
    listaArtistas()
    {
        primerElemento = nullptr;
    }
    ~listaArtistas()
    {
        if (primerElemento != nullptr)
        {
            artista *temp = primerElemento->siguienteElemento;
            while (temp != primerElemento)
            {
                artista *eliminar = temp;
                temp = temp->siguienteElemento;
                delete eliminar;
            }
            delete primerElemento;
        }
    }

    bool insertarArtista(int ID, string nombreArtistico, string nombreReal, string pais, int selloDiscografico)
    {
        artista *nuevoArtista = new artista(ID, nombreArtistico, nombreReal, pais, selloDiscografico);

        if (primerElemento == nullptr)
        {
            primerElemento = nuevoArtista;
            return true;
        }

        artista *temp = primerElemento;

        while (temp != nullptr)
        {
            if (temp->ID == ID)
            {
                delete nuevoArtista;
                return false;
            }
            temp = temp->siguienteElemento;
        }

        temp = primerElemento;
        artista *anterior = nullptr;

        while (temp != nullptr && temp->nombreArtistico < nombreArtistico)
        {
            anterior = temp;
            temp = temp->siguienteElemento;
        }

        if (anterior == nullptr)
        {
            nuevoArtista->siguienteElemento = primerElemento;
            primerElemento->anteriorElemento = nuevoArtista;
            primerElemento = nuevoArtista;
        }
        else
        {
            nuevoArtista->siguienteElemento = temp;
            nuevoArtista->anteriorElemento = anterior;
            anterior->siguienteElemento = nuevoArtista;
            if (temp != nullptr)
            {
                temp->anteriorElemento = nuevoArtista;
            }
        }

        return true;
    }

    bool modificar(int ID, string nombreArtistico, string nombreReal, string pais, int selloDiscografico, listaCanciones * lstCanciones, listaAlbumes * lstAlbumes)
    {
        artista *temp = primerElemento;
        while (temp)
        {
            if (temp->ID == ID)
            {
                temp->nombreArtistico=nombreArtistico;
                temp->nombreReal=nombreReal;
                temp->pais=pais;
                temp->selloDiscografico=selloDiscografico;
                temp->lstCanciones=lstCanciones;
                temp->lstAlbumes=lstAlbumes;
                return true;
            }
            temp = temp->siguienteElemento;
        }
        return false;
    }

    
    bool eliminar(int id)
    {
        if (primerElemento == nullptr)
        {
            return false;
        }
    
        artista *temp = primerElemento;
    
        if (temp->ID == id)
        {
            primerElemento = temp->siguienteElemento;
            if (primerElemento != nullptr)
            {
                primerElemento->anteriorElemento = nullptr;
            }
            delete temp;
            return true;
        }
    
        while (temp != nullptr)
        {
            if (temp->ID == id)
            {
                if (temp->anteriorElemento != nullptr)
                {
                    temp->anteriorElemento->siguienteElemento = temp->siguienteElemento;
                }
                if (temp->siguienteElemento != nullptr)
                {
                    temp->siguienteElemento->anteriorElemento = temp->anteriorElemento;
                }
                delete temp;
                return true;
            }
            temp = temp->siguienteElemento;
        }
    
        return false;
    }
    

};

#endif
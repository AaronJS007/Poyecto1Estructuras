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

    int cantidad(){
        if (primerElemento==nullptr){
            return 0;
        }
        artista * temp = primerElemento;
        int cantidad=0;
        while (temp){
            cantidad++;
            temp = temp->siguienteElemento;
        }
        return cantidad;
    }

    void artistaMasAlbumes(){
        artista* temp = primerElemento;
        string nombre = "";
        int cantidad = 0;
        int cantidad2 = 0;
        while (temp){
            cantidad2 = temp->lstAlbumes->cantidad();
            if ( cantidad2 > cantidad)
            {
                cantidad=cantidad2;
                nombre=temp->nombreArtistico;
            }
           temp=temp->siguienteElemento;
        }
        if(cantidad!=0){
            cout << "El artista con mas albumes es: " << nombre << "\n";
        }else{
            cout << "No hay artistas con albumes \n";
        } 
    }

    void CantidadAlbumesPorArtista(){
        artista* temp = primerElemento;
        while (temp) {
            cout << "Nombre artista: " << temp -> nombreArtistico;
            cout << "Cantidad albumes: " << temp->lstAlbumes->cantidad();
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }

    void imprimir() {
        artista* temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->ID << endl;
            cout << "Título: " << temp->titulo << endl;
            cout << "Duración: " << temp->duracion << " segundos" << endl;
            cout << "Año: " << temp->anno << endl;
            cout << "ID Álbum: " << temp->idAlbum << endl;
            cout << "ID Artista: " << temp->idArtista << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }
    

};

#endif
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

    bool insertarArtista(artista * nuevoArtista)
    {

        if (primerElemento == nullptr)
        {
            primerElemento = nuevoArtista;
            return true;
        }

        artista *temp = primerElemento;

        while (temp != nullptr)
        {
            if (temp->ID == nuevoArtista->ID)
            {
                delete nuevoArtista;
                return false;
            }
            temp = temp->siguienteElemento;
        }

        temp = primerElemento;
        artista *anterior = nullptr;

        while (temp != nullptr && temp->nombreArtistico < nuevoArtista->nombreArtistico)
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

    bool modificar(int ID, string nombreArtistico, string nombreReal, string pais)
    {
        artista *temp = primerElemento;
        while (temp)
        {
            if (temp->ID == ID)
            {
                temp->nombreArtistico=nombreArtistico;
                temp->nombreReal=nombreReal;
                temp->pais=pais;
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

    int buscarArtistaPorNombre(string nombre){
        artista* temp = primerElemento;
        while (temp) {
            if(temp->nombreArtistico==nombre||temp->nombreReal==nombre){
                return temp->ID;
            }
            temp = temp->siguienteElemento;
        }
        return -1;
    }

    bool incertarCancionArtista(cancion* nueva){
        artista* temp = primerElemento;
        while (temp) {
            if(temp->ID==nueva->idArtista){
                return temp->lstCanciones->incercionInicio(nueva);
            }
            temp = temp->siguienteElemento;
        }
        return false;
    }

    bool incertarAlbumArtista(album* nuevo){
        artista* temp = primerElemento;
        while (temp) {
            if(temp->ID==nuevo->idArtista){
                return temp->lstAlbumes->incercionFinal(nuevo);
            }
            temp = temp->siguienteElemento;
        }
        return false;
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

    void imprimirSimple() {
        artista* temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->ID << endl;
            cout << "Nombre artistico: " << temp->nombreArtistico << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }

    void imprimir() {
        artista* temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->ID << endl;
            cout << "Nombre artistico: " << temp->nombreArtistico << endl;
            cout << "Nombre real: " << temp->nombreReal << " segundos" << endl;
            cout << "Pais: " << temp->pais << endl;
            cout << "Sello discografico: " << temp->selloDiscografico << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }
    

};

#endif
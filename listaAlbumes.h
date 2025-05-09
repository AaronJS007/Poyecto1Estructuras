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

    bool incercionFinal(album*Nuevo)
    {
        try
        {
            if (primerElemento == nullptr)
            {
                primerElemento = Nuevo;
            }
            else
            {
                album *temp = primerElemento;
                while (temp->siguienteElemento != nullptr)
                {
                    if (temp->IDAlbum == Nuevo->IDAlbum)
                    {
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

    bool modificar(int ID,string titulo,int anno)
    {
        album *temp = primerElemento;
        while (temp)
        {
            if (temp->IDAlbum == ID)
            {
                temp->titulo = titulo;
                temp->anno = anno;
                temp->numeroCanciones=temp->lstCanciones->cantidadCanciones();
                temp->lstCanciones;
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
        album *temp = primerElemento;

        if (primerElemento->IDAlbum == id)
        {
            primerElemento = primerElemento->siguienteElemento;
            delete temp;
            return true;
        }

        while (temp->siguienteElemento != nullptr)
        {
            if (temp->siguienteElemento->IDAlbum == id)
            {
                album *eliminar = temp->siguienteElemento;
                temp->siguienteElemento = eliminar->siguienteElemento;
                delete eliminar;
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
        album * temp = primerElemento;
        int cantidad=0;
        while (temp){
            cantidad++;
            temp = temp->siguienteElemento;
        }
        return cantidad;
    }

    int buscarArtistaPorNombre(string nombre){
        album* temp = primerElemento;
        while (temp) {
            if(temp->titulo==nombre){
                return temp->IDAlbum;
            }
            temp = temp->siguienteElemento;
        }
        return -1;
    }

    bool incertarCancionAlbum(cancion* nueva){
        album* temp = primerElemento;
        while (temp) {
            if(temp->idArtista==nueva->idArtista){
                return temp->lstCanciones->incercionInicio(nueva);
            }
            temp = temp->siguienteElemento;
        }
        return false;
    }

    void AlbumesConCancionesMayores(int numero){
        album * temp = primerElemento;
        while (temp) {
            if (temp->numeroCanciones > numero)
            {
            cout << "ID: " << temp->IDAlbum << endl;
            cout << "Título: " << temp->titulo << endl;
            cout << "Año: " << temp->anno << endl;
            cout << "Numero de Canciones: " << temp->numeroCanciones << endl;
            cout << "ID Artista: " << temp->idArtista << endl;
            cout << "--------------------------" << endl;
            }
            temp = temp->siguienteElemento;
        }
    }

    void imprimirSimple(){
        album * temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->IDAlbum << endl;
            cout << "Título: " << temp->titulo << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }

    void imprimir(){
        album * temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->IDAlbum << endl;
            cout << "Título: " << temp->titulo << endl;
            cout << "Año: " << temp->anno << endl;
            cout << "Numero de Canciones: " << temp->numeroCanciones << endl;
            cout << "ID Artista: " << temp->idArtista << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }
};

#endif


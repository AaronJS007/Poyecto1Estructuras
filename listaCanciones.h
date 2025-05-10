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

    bool incercionInicio(cancion * Nuevo)
    {
        try
        {
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

    bool modificar(int ID, string nuevoTitulo, int nuevaDuracion, int nuevoAnno)
    {
        cancion *temp = primerElemento;
        while (temp)
        {
            if (temp->ID == ID)
            {
                temp->titulo = nuevoTitulo;
                temp->duracion = nuevaDuracion;
                temp->anno = nuevoAnno;
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

    int cantidadCanciones(){
        if (primerElemento==nullptr){
            return 0;
        }
        cancion * temp = primerElemento;
        int cantidad=0;
        while (temp){
            cantidad++;
            temp = temp->siguienteElemento;
        }
        return cantidad;
    }

    cancion * cancionMasLarga(){
        cancion* respuesta = primerElemento;
        cancion* temp = primerElemento;
        while (temp) {
            if (temp->duracion>respuesta->duracion)
            {
                respuesta = temp;
            }
            
            temp = temp->siguienteElemento;
        }
        return respuesta;
    }

    cancion * buscar(int id){
        cancion* respuesta = primerElemento;
        cancion* temp = primerElemento;
        while (temp) {
            if (temp->ID==id)
            {
                return temp;
            }
            temp = temp->siguienteElemento;
        }
        return nullptr;
    }

    void cancionesPublicadas(int anno){
        cancion* temp = primerElemento;
        while (temp) {
            if (temp->anno==anno){
            cout << "ID: " << temp->ID << endl;
            cout << "Titulo: " << temp->titulo << endl;
            cout << "Duracion: " << temp->duracion << " segundos" << endl;
            cout << "Anio: " << temp->anno << endl;
            cout << "ID Album: " << temp->idAlbum << endl;
            cout << "ID Artista: " << temp->idArtista << endl;
            cout << "--------------------------" << endl;
            }
            temp = temp->siguienteElemento;
        }
    }

    void imprimirSimple() {
        cancion* temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->ID << endl;
            cout << "Titulo: " << temp->titulo << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }

    void imprimir() {
        cancion* temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->ID << endl;
            cout << "Titulo: " << temp->titulo << endl;
            cout << "Duracion: " << temp->duracion << " segundos" << endl;
            cout << "Anio: " << temp->anno << endl;
            cout << "ID Album: " << temp->idAlbum << endl;
            cout << "ID Artista: " << temp->idArtista << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }
    
};

#endif

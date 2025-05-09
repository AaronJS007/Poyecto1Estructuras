#ifndef LISTAPLAYLIST_H
#define LISTAPLAYLIST_H
#include <iostream>
using namespace std;
#include"playlist.h"
//lista simple insercion inici

struct listaPlaylist{
    playlist * primerElemento;

    listaPlaylist(){
        primerElemento=nullptr;
    }

    bool incercionInicio(int pId, string pNombre, string pCreador, int pFecha){
        playlist * nuevo = new playlist(pId, pNombre, pCreador, pFecha);
        if (primerElemento == nullptr) {
            primerElemento = nuevo;
            return true;  
        } else {
            playlist * temp = primerElemento;
            while (temp) {
                if (temp->id == pId) {
                    delete nuevo;
                    return false;  
                }
                temp = temp->siguienteElemento;
            }
            nuevo->siguienteElemento = primerElemento;
            primerElemento = nuevo;
            return true;  
        }
    }
    

    bool modificar(int pId, string pNombre, string pCreador)
    {
        playlist *temp = primerElemento;
        while (temp)
        {
            if (temp->id == pId)
            {
                temp->nombre = pNombre;
                temp->creador = pCreador;
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
        playlist *temp = primerElemento;

        if (primerElemento->id == id)
        {
            primerElemento = primerElemento->siguienteElemento;
            delete temp;
            return true;
        }

        while (temp->siguienteElemento != nullptr)
        {
            if (temp->siguienteElemento->id == id)
            {
                playlist *eliminar = temp->siguienteElemento;
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
        
        playlist * temp = primerElemento;
        int cantidad=0;
        while (temp){
            cantidad++;
            temp = temp->siguienteElemento;
        }
        return cantidad;
    }

    playlist * buscar(int id){
        playlist* respuesta = primerElemento;
        playlist* temp = primerElemento;
        while (temp) {
            if (temp->id==id)
            {
                return temp;
            }
            temp = temp->siguienteElemento;
        }
        return nullptr;
    }

    void playlistMasCanciones(){
        playlist * temp = primerElemento;
        string nombre = "";
        int cantidad = 0;
        int cantidad2 = 0;
        while (temp){
            cantidad2 = temp->lstCanciones->cantidadCanciones();
            if ( cantidad2 > cantidad)
            {
                cantidad=cantidad2;
                nombre=temp->nombre;
            }
           temp=temp->siguienteElemento;
        }
        if(cantidad!=0){
            cout << "La playlist con mas canciones es: " << nombre << "\n";
        }else{
            cout << "No hay playlist con canciones \n";
        } 
    }

    void imprimirSimple(){
        playlist * temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->id << endl;
            cout << "Nombre: " << temp->nombre << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }

    void imprimir(){
        playlist * temp = primerElemento;
        while (temp) {
            cout << "ID: " << temp->id << endl;
            cout << "Nombre: " << temp->nombre << endl;
            cout << "Creado por : " << temp->creador << endl;
            cout << "Numero de Canciones: " << temp->lstCanciones->cantidadCanciones() << endl;
            cout << "Fecha de creacion: " << temp->fecha << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        }
    }

};

#endif
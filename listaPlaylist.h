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

    bool incercionInicio(int pId, string pNombre, string pCreador, string pFecha){
        playlist * nuevo = new playlist(pId,pNombre,pCreador,pFecha);
        if (primerElemento==nullptr){
            primerElemento=nuevo;
        }else{
            playlist * temp = primerElemento;
            while (temp){
                if (temp->id==pId){
                    delete nuevo;
                    return false;
                }
                temp=temp->siguienteElemento;
            }
            nuevo->siguienteElemento=primerElemento;
            primerElemento=nuevo;
            return true;
        }
    }

    bool modificar(int pId, string pNombre, string pCreador, string pFecha)
    {
        playlist *temp = primerElemento;
        while (temp)
        {
            if (temp->id == pId)
            {
                temp->nombre = pNombre;
                temp->creador = pCreador;
                temp->fecha = pFecha;
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
        
        album * temp = primerElemento;
        int cantidad=0;
        while (temp){
            cantidad++;
            temp = temp->siguienteElemento;
        }
        return cantidad;
    }
};

#endif
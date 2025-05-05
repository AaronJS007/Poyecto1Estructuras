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
                
            }
            
        }
    }
};

#endif
#ifndef LISTABATALLAS_H
#define LISTABATALLAS_H
#include <iostream>
#include "nodoBatallas.h"

struct listaBatallas{
    nodoBatallas * primerElemento;
    int contador;
    
    listaBatallas(){
        primerElemento=nullptr;
        contador=0;
    }
    ~listaBatallas(){
        if (!primerElemento) return;

        nodoBatallas* temp = primerElemento;
        nodoBatallas* siguiente;
        do {
            siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        } while (temp != primerElemento);

        primerElemento = nullptr;
        contador = 0;
    }

    bool NuevaBatalla(nodoEntrenador* pEntrenador1, nodoEntrenador* pEntrenador2) {
        if (!pEntrenador1 || !pEntrenador2) {
            return false;
        }

        nodoBatallas* nuevo = new nodoBatallas(pEntrenador1, pEntrenador2);

        if (!primerElemento) {
            primerElemento = nuevo;
            primerElemento->siguiente = primerElemento;
            primerElemento->anterior = primerElemento;
        } else {
            nodoBatallas* ultimo = primerElemento->anterior;
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            nuevo->siguiente = primerElemento;
            primerElemento->anterior = nuevo;
        }

        contador++;
        return true;
    }

    void BatallaResumen(nodoBatallas * Batalla){
        cout << "Batalla pokemon:"<<endl;
        cout << "Ganador: "<< Batalla->ganador->nombre << endl;
        cout << "Perdedor: "<< Batalla->perdedor->nombre << endl;
    }

    void listarBatallas(){
        if(!primerElemento){
            cout << "No hay batallas para mostrar"<< endl;
        }else{
            nodoBatallas * temp = primerElemento;
            do {
                BatallaResumen(temp);
                temp = temp->siguiente;
            } while (temp != primerElemento);
            
        }
    }
};
#endif
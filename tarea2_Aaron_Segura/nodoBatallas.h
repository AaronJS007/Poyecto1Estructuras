#ifndef BATALLAS_H
#define BATALLAS_H
#include <iostream>
#include "nodoEntrenador.h"
using namespace std;
struct nodoBatallas{
    nodoEntrenador * ganador;
    nodoEntrenador * perdedor;

    nodoBatallas * siguiente;
    nodoBatallas * anterior;

    

    nodoBatallas(nodoEntrenador * entrenador1,nodoEntrenador * entrenador2){
        
        if(entrenador1->nivel==entrenador2->nivel){
            if (rand() % 2) swap(entrenador1, entrenador2);
            ganador = entrenador1;
            perdedor = entrenador2;
        }else{
            if (entrenador1->nivel*(entrenador1->pokemones->contador)>entrenador2->nivel*(entrenador2->pokemones->contador)){
                ganador=entrenador1;
                perdedor=entrenador2;
            }else{
                ganador=entrenador2;
                perdedor=entrenador1;
            }
        }
        ganador->win++;
        perdedor->lose++;

        if(!ganador->win%10==0){
            ganador->nivel++;
        }
        if(!perdedor->lose%10==0 && perdedor->nivel>1){
            perdedor->nivel--;
        }

        siguiente=nullptr;
        anterior=nullptr;
    }

};


#endif
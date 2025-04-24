#ifndef ENTRENADOR_H
#define ENTRENADOR_H
#include "listaPokemon.h"
#include <iostream>
using namespace std;
struct nodoEntrenador{
    int id;
    string nombre;
    int nivel;
    int win;
    int lose;
    listaPokemon * pokemones;
    nodoEntrenador * siguiente;
    nodoEntrenador * anterior;

    nodoEntrenador(int pId,string Pnombre,int pNivel,int pWin,int pLose){
        id = pId;
        nombre = Pnombre;
        nivel = pNivel;
        win = pWin;
        lose = pLose;
        pokemones = new listaPokemon();
        siguiente = nullptr;
        anterior = nullptr;
    }
    ~nodoEntrenador(){delete pokemones;}

    void caracteristicas(){
        cout << "Identificador: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Nivel de Entrenador: " << nivel << endl;
        cout << "Batallas ganadas: " << win << endl;
        cout << "Batallas perdidas: " << lose << endl;
        pokemones->mostrarLista();
    }
};
#endif
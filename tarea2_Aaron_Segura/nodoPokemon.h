#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
using namespace std;
struct nodoPokemon
{
    string nombre;
    int nivel;
    nodoPokemon * siguiente;

    nodoPokemon(string nombreP, int nivelP){
        nombre=nombreP;
        nivel=nivelP;
        siguiente=nullptr;
    }
};
#endif
#ifndef LISTAPOKEMON_H
#define LISTAPOKEMON_H
#include <iostream>
#include "nodoPokemon.h"
using namespace std;

struct listaPokemon {
public:
    nodoPokemon* primerElemento;
    int contador;

    listaPokemon() {
        contador = 0;
        primerElemento = nullptr;
    }

    ~listaPokemon() {
        nodoPokemon* temp;
        while (primerElemento) {
            temp = primerElemento;
            primerElemento = primerElemento->siguiente;
            delete temp;
        }
    }

    bool AgregarPokemon(string pNombre, int pNivel) {
        try {
            nodoPokemon* nuevo = new nodoPokemon(pNombre, pNivel);
            if (primerElemento == nullptr) {
                primerElemento = nuevo;
            } else {
                nodoPokemon* temp = primerElemento;
                while (temp->siguiente != nullptr) {
                    temp = temp->siguiente;
                }
                temp->siguiente = nuevo;
            }
            contador++;
            return true;
        } catch (const exception& e) {
            cerr << e.what() << '\n';
            return false;
        }
    }

    bool modificarPokemon(string pnombre, int pnivel) {
        nodoPokemon* temp = primerElemento;
        while (temp) {
            if (temp->nombre == pnombre) {
                temp->nivel = pnivel;
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }

    bool eliminarPokemon(string pnombre) {
        if (primerElemento == nullptr) {
            cout << "La lista está vacía, no se puede eliminar" << endl;
            return false;
        }

        if (primerElemento->nombre == pnombre) {
            nodoPokemon* temp = primerElemento;
            primerElemento = primerElemento->siguiente;
            delete temp;
            contador--;
            cout << "El Pokémon ha sido eliminado" << endl;
            return true;
        }

        nodoPokemon* temp = primerElemento;
        while (temp->siguiente != nullptr && temp->siguiente->nombre != pnombre) {
            temp = temp->siguiente;
        }

        if (temp->siguiente == nullptr) {
            cout << "El Pokémon no se encontró en la lista" << endl;
            return false;
        }

        nodoPokemon* eliminar = temp->siguiente;
        temp->siguiente = eliminar->siguiente;
        delete eliminar;
        contador--;
        cout << "El Pokémon ha sido eliminado" << endl;
        return true;
    }

    int sumaBatalla() {
        int suma = 0;
        nodoPokemon* temp = primerElemento;
        while (temp) {
            suma += temp->nivel;
            temp = temp->siguiente;
        }
        return suma;
    }

    void mostrarLista() {
        if (!primerElemento) {
            cout << "No hay Pokémones" << endl;
            return;
        }

        cout << "Lista de Pokémones: " << endl;
        nodoPokemon* temp = primerElemento;
        while (temp) {
            cout << "Nombre: " << temp->nombre << ", Nivel: " << temp->nivel << endl;
            temp = temp->siguiente;
        }
    }
};

#endif

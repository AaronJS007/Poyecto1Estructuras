#include <iostream>
using namespace std;
#include "nodoEntrenador.h"

struct ListaEntrenadores {
    nodoEntrenador* PrimerElemento;
    int contador;

    ListaEntrenadores() {
        PrimerElemento = nullptr;
        contador = 0;
    }

    ~ListaEntrenadores() {
        nodoEntrenador* temp;
        while (PrimerElemento) {
            temp = PrimerElemento;
            PrimerElemento = PrimerElemento->siguiente;
            delete temp; 
        }
    }

    bool AgregarEntrenador(int id, string Pnombre, int Pnivel) {
        try {
            nodoEntrenador* nuevo = new nodoEntrenador(id, Pnombre, Pnivel, 0, 0);
            if (PrimerElemento == nullptr) {
                PrimerElemento = nuevo;
            } else {
                nodoEntrenador* temp = PrimerElemento;
                while (temp->siguiente != nullptr) {
                    temp = temp->siguiente;
                }
                temp->siguiente = nuevo;
                nuevo->anterior = temp;
            }
            contador++;
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return false;
        }
    }

    bool modificarNivelEntrenador(int pid, int pnivel) {
        nodoEntrenador* temp = PrimerElemento;
        while (temp) {
            if (temp->id == pid) {
                temp->nivel = pnivel;
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }

    bool eliminarPorID(int pId) {
        if (PrimerElemento == nullptr) {
            return false; 
        }

        nodoEntrenador* temp = PrimerElemento;
        while (temp) {
            if (temp->id == pId) {
                if (temp == PrimerElemento) {
                    PrimerElemento = temp->siguiente;
                    if (PrimerElemento) {
                        PrimerElemento->anterior = nullptr;
                    }
                } else {
                    if (temp->siguiente == nullptr) {
                        temp->anterior->siguiente = nullptr;
                    } else {
                        temp->anterior->siguiente = temp->siguiente;
                        temp->siguiente->anterior = temp->anterior;
                    }
                }
                delete temp;
                contador--;
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }

    nodoEntrenador* BuscarEntrenador(int pid) {
        nodoEntrenador* temp = PrimerElemento;
        while (temp) {
            if (temp->id == pid) {
                return temp;
            }
            temp = temp->siguiente;
        }
        return nullptr;
    }

    int TotalPokemones() {
        nodoEntrenador* temp = PrimerElemento;
        int total = 0;
        while (temp) {
            total += temp->pokemones->contador;
            temp = temp->siguiente;
        }
        return total;
    }

    void mostrarEntrenadores() {
        nodoEntrenador* temp = PrimerElemento;
        while (temp) {
            temp->caracteristicas(); 
            temp = temp->siguiente;
        }
    }
};


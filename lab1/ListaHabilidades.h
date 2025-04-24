#ifndef LISTAHABILIDADES_H
#define LISTAHABILIDADES_H
#include <iostream>
#include "Habilidad.h"
using namespace std;

class ListaHabilidades
{
public:
    Habilidad * PrimerElemento;

    ListaHabilidades(){
        PrimerElemento=nullptr;
    }
    ~ListaHabilidades();

    Habilidad * insertar(string nombreP, string tipoP){
        try{
            Habilidad * Nuevo = new Habilidad(nombreP, tipoP);
            if (PrimerElemento==nullptr){
                PrimerElemento=Nuevo;
                cout << "La habilidad se creo correctamente" << endl;
                return PrimerElemento;
            }
            Habilidad * temp = PrimerElemento;
            while (temp->siguiente!=nullptr){
                temp=temp->siguiente;
            }
            temp->siguiente=Nuevo;
            cout << "La habilidad se creo correctamente" << endl;
            return PrimerElemento;
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';
            cout << "No se puedo agregar la habilidad" << endl;
            return nullptr;
        }
    }

    bool eliminarPorNombre(string nombreP) {
        if (PrimerElemento == nullptr) {
            cout << "La lista está vacía, no se puede eliminar." << endl;
            return false;
        }
    
        if (PrimerElemento->nombre == nombreP) {
            Habilidad* temp = PrimerElemento;
            PrimerElemento = PrimerElemento->siguiente;
            delete temp;
            cout << "La habilidad " << nombreP << " ha sido eliminada." << endl;
            return true;
        }
    
        Habilidad* actual = PrimerElemento;
        while (actual->siguiente != nullptr && actual->siguiente->nombre != nombreP) {
            actual = actual->siguiente;
        }
    
        if (actual->siguiente == nullptr) {
            cout << "La habilidad " << nombreP << " no se encontró en la lista." << endl;
            return false;
        }

        Habilidad* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        delete temp;
        cout << "La habilidad " << nombreP << " ha sido eliminada." << endl;
        return true;
    }

    

};
#endif
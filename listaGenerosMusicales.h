#ifndef LISTAGENEROSMUSICALES_H
#define LISTAGENEROSMUSICALES_H
#include <iostream>
using namespace std;
#include "generoMusical.h"

struct listaGenerosMusicales
{
    generoMusical *primerElemento;
    listaGenerosMusicales()
    {
        primerElemento = nullptr;
    }
    ~listaGenerosMusicales()
    {
        if (primerElemento == nullptr){return;}
        generoMusical *temp;
        primerElemento->anteriorElemento->siguienteElemento = nullptr;
        while (primerElemento)
        {
            temp = primerElemento;
            primerElemento = primerElemento->siguienteElemento;
            delete temp;
        }
    }
    
    bool incercionFinal(int pId, string pNombre, string pDescripcion)
    {
        try
        {
            generoMusical *Nuevo = new generoMusical(pId, pNombre, pDescripcion);
            if (primerElemento == nullptr)
            {
                Nuevo->siguienteElemento = Nuevo;
                Nuevo->anteriorElemento = Nuevo;
                primerElemento = Nuevo;
            }
            else
            {
                generoMusical *temp = primerElemento;
                do
                {
                    if (temp->IdGeneroMusical == Nuevo->IdGeneroMusical)
                    {
                        delete Nuevo;
                        return false;
                    }
                    temp = temp->siguienteElemento;
                } while (temp != primerElemento);
    
                temp = primerElemento->anteriorElemento;
                temp->siguienteElemento = Nuevo;
                Nuevo->anteriorElemento = temp;
                Nuevo->siguienteElemento = primerElemento;
                primerElemento->anteriorElemento = Nuevo;
            }
            return true;
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
            return false;
        }
    }
    
    bool modificar(int pId, string pNombre, string pDescripcion)
    {
        if (primerElemento == nullptr)
            return false;
    
        generoMusical *temp = primerElemento;
        do
        {
            if (temp->IdGeneroMusical == pId)
            {
                temp->nombre = pNombre;
                temp->descripcion = pDescripcion;
                return true;
            }
            temp = temp->siguienteElemento;
        } while (temp != primerElemento);
    
        return false;
    }
    
    bool eliminar(int id)
    {
        if (primerElemento == nullptr)
            return false;
    
        generoMusical* temp = primerElemento;
    
        // Caso especial: solo un nodo y es el que queremos eliminar
        if (temp->IdGeneroMusical == id && temp->siguienteElemento == primerElemento)
        {
            delete temp;
            primerElemento = nullptr;
            return true;
        }
    
        // Caso especial: primer nodo a eliminar
        if (temp->IdGeneroMusical == id)
        {
            generoMusical* ultimo = primerElemento->anteriorElemento;
            primerElemento = primerElemento->siguienteElemento;
            ultimo->siguienteElemento = primerElemento;
            primerElemento->anteriorElemento = ultimo;
            delete temp;
            return true;
        }
    
        // Resto de la lista
        temp = temp->siguienteElemento;
        while (temp != primerElemento)
        {
            if (temp->IdGeneroMusical == id)
            {
                temp->anteriorElemento->siguienteElemento = temp->siguienteElemento;
                temp->siguienteElemento->anteriorElemento = temp->anteriorElemento;
                delete temp;
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
        
        generoMusical * temp = primerElemento;
        int cantidad=0;
        do
        {
            cantidad++;
            temp=temp->siguienteElemento;
        } while (temp!=primerElemento);
        
        return cantidad;
    }

    void generoMasCanciones() {
        if (primerElemento == nullptr) {
            cout << "No hay géneros registrados.\n";
            return;
        }
    
        generoMusical* temp = primerElemento;
        string nombre = "";
        int cantidad = 0;
    
        do {
            int cantidad2 = temp->lstCanciones->cantidad();  // asumimos que existe el método cantidad()
            if (cantidad2 > cantidad) {
                cantidad = cantidad2;
                nombre = temp->nombre;
            }
            temp = temp->siguienteElemento;
        } while (temp != primerElemento);
    
        if (cantidad != 0) {
            cout << "El género con más canciones es: " << nombre << " (" << cantidad << " canciones)\n";
        } else {
            cout << "No hay géneros con canciones.\n";
        }
    }    

};    


#endif
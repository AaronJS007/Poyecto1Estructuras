#ifndef LISTASELLODISCOGRAFICO_H
#define LISTASELLODISCOGRAFICO_H
#include <iostream>
using namespace std;
#include"selloDiscografico.h"

struct listaSelloDiscografico
{
    selloDiscografico *primerElemento;
    listaSelloDiscografico()
    {
        primerElemento = nullptr;
    }
    ~listaSelloDiscografico()
    {
        if (primerElemento == nullptr){return;}
        selloDiscografico *temp;
        primerElemento->anteriorElemento->siguienteElemento = nullptr;
        while (primerElemento)
        {
            temp = primerElemento;
            primerElemento = primerElemento->siguienteElemento;
            delete temp;
        }
    }
    
    bool incercionFinal(int pId, string pNombre, string pPais,int pAnno)
    {
        try
        {
            selloDiscografico *Nuevo = new selloDiscografico(pId, pNombre, pPais,pAnno);
            if (primerElemento == nullptr)
            {
                Nuevo->siguienteElemento = Nuevo;
                Nuevo->anteriorElemento = Nuevo;
                primerElemento = Nuevo;
            }
            else
            {
                selloDiscografico *temp = primerElemento;
                do
                {
                    if (temp->id == Nuevo->id)
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
    
    bool modificar(int pId, string pNombre, string pPais,int pAnno)
    {
        if (primerElemento == nullptr)
            return false;
    
            selloDiscografico *temp = primerElemento;
        do
        {
            if (temp->id == pId)
            {
                temp->nombre = pNombre;
                temp->pais = pPais;
                temp->annoFundacion=pAnno;
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
    
            selloDiscografico* temp = primerElemento;
    
        // Caso especial: solo un nodo y es el que queremos eliminar
        if (temp->id == id && temp->siguienteElemento == primerElemento)
        {
            delete temp;
            primerElemento = nullptr;
            return true;
        }
    
        // Caso especial: primer nodo a eliminar
        if (temp->id == id)
        {
            selloDiscografico* ultimo = primerElemento->anteriorElemento;
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
            if (temp->id == id)
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
        
        selloDiscografico * temp = primerElemento;
        int cantidad=0;
        do
        {
            cantidad++;
            temp=temp->siguienteElemento;
        } while (temp!=primerElemento);
        
        return cantidad;
    }

    void selloConMasArtistas(){
        if (primerElemento == nullptr) {
            cout << "No hay sellos discográficos registrados.\n";
            return;
        }
    
        selloDiscografico* temp = primerElemento;
        string nombre = "";
        int maxArtistas = 0;
        int cantidad = 0;
    
        do {
            cantidad = temp->lstArtistas->cantidad();
            if (cantidad > maxArtistas) {
                maxArtistas = cantidad;
                nombre = temp->nombre;
            }
            temp = temp->siguienteElemento;
        } while (temp != primerElemento);
    
        if (maxArtistas > 0) {
            cout << "El sello con más artistas es: " << nombre << " (" << maxArtistas << " artistas)\n";
        } else {
            cout << "No hay artistas registrados en los sellos.\n";
        }
    }
    
};    

#endif
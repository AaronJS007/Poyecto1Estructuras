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
    
    bool modificar(int pId, string pNombre, string pPais)
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

    bool ExisteElSello(int id){
        if (primerElemento == nullptr) {
            cout << "No hay sellos discográficos registrados.\n";
            return false;
        }
    
        selloDiscografico* temp = primerElemento;
    
        do {
            if (temp->id == id) {
                return true;
            }
            temp = temp->siguienteElemento;
        } while (temp != primerElemento);
        return false;
    }
    bool AgregarArtistaAlSello(artista* nuevo){
        if (primerElemento == nullptr) {
            cout << "No hay sellos discográficos registrados.\n";
            return false;
        }
    
        selloDiscografico* temp = primerElemento;
    
        do {
            if (temp->id == nuevo->selloDiscografico) {
                return (temp->lstArtistas->insertarArtista(nuevo));
            }
            temp = temp->siguienteElemento;
        } while (temp != primerElemento);
        return false;
    }

    void imprimirSimple() {
        if (primerElemento == nullptr) {
            cout << "No hay géneros musicales registrados.\n";
            return;
        }
    
        selloDiscografico* temp = primerElemento;
        do {
            cout << "ID sello: " << temp->id << endl;
            cout << "Nombre: " << temp->nombre << endl;
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        } while (temp != primerElemento);
    }

    void imprimir() {
        if (primerElemento == nullptr) {
            cout << "No hay géneros musicales registrados.\n";
            return;
        }
    
        selloDiscografico* temp = primerElemento;
        do {
            cout << "ID sello: " << temp->id << endl;
            cout << "Nombre: " << temp->nombre << endl;
            cout << "pais: " << temp->pais << endl;
            cout << "año de fundacion: " << temp->annoFundacion << endl;
            cout << "Cantidad de artistas: " << (temp->lstArtistas ? temp->lstArtistas->cantidad() : 0) << endl;
            temp->lstArtistas->imprimirSimple();
            cout << "--------------------------" << endl;
            temp = temp->siguienteElemento;
        } while (temp != primerElemento);
    }
    
};    

#endif
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
    
                generoMusical* ultimo = primerElemento->anteriorElemento;
                ultimo->siguienteElemento = Nuevo;
                Nuevo->anteriorElemento = ultimo;
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
    
        generoMusical *temp = primerElemento;
    
        if (temp->IdGeneroMusical == id)
        {
            if (temp->siguienteElemento == temp)
            {
                delete temp;
                primerElemento = nullptr;
                return true;
            }
            else
            {
                generoMusical *ultimo = primerElemento->anteriorElemento;
                primerElemento = primerElemento->siguienteElemento;
                ultimo->siguienteElemento = primerElemento;
                primerElemento->anteriorElemento = ultimo;
                delete temp;
                return true;
            }
        }
    
        do
        {
            if (temp->siguienteElemento->IdGeneroMusical == id)
            {
                generoMusical *eliminar = temp->siguienteElemento;
                temp->siguienteElemento = eliminar->siguienteElemento;
                eliminar->siguienteElemento->anteriorElemento = temp;
                delete eliminar;
                return true;
            }
            temp = temp->siguienteElemento;
        } while (temp != primerElemento);
    
        return false;
    }
};    

#endif
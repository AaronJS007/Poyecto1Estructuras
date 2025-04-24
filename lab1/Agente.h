#include <iostream>
#include <sstream>
using namespace std;
#include "ListahabPropias.h"

struct Agente{
    string nombre;
    string rol;
    int nivel_habilidad;
    ListahabPropias * propias;
    Agente*siguiente;
    Agente*anterior;

    Agente(string Pnombre, string Prol, int Pnivel_habilidad){
        nombre=Pnombre;
        rol=Prol;
        nivel_habilidad=Pnivel_habilidad;
        propias=new ListahabPropias();
        siguiente=nullptr;
        anterior=nullptr;
    }

    string toString(){
        std::ostringstream ss;
        ss << "Nombre del Agente: " << nombre << "\n"
           << "Rol del Agente: " << rol << "\n"
           << "Nivel de Habilidad: " << nivel_habilidad << "\n";
    
        if (propias != nullptr) {  
            ss << propias->toString();
        }
    
        return ss.str(); 
    }
};




#include <iostream>
using namespace std;
#include "HabilidadesPropias.h"

class ListahabPropias
{
public:
    HabilidadesPropias * PrimerElemento;
    ListahabPropias(){
        PrimerElemento=nullptr;
    }
    ~ListahabPropias();

    bool agregar(Habilidad*pHabilidad){
        try
        {
            HabilidadesPropias * nuevo = new HabilidadesPropias(pHabilidad);
            if(PrimerElemento==nullptr){
                PrimerElemento=nuevo;
                return true;
            }
            HabilidadesPropias * temp = PrimerElemento;
            while (temp->siguiente!=nullptr){
                temp=temp->siguiente;
            }
            temp->siguiente = nuevo;
            return true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            cout << "Error al agregar la habilidad propia";
            return false;
        }
        
    }

    string getNombrePrimerElemento(){
        if(PrimerElemento==nullptr){
            return"-1";
        }
        return PrimerElemento->habilidad->nombre;
    }

    bool estavacio(){
        if (PrimerElemento==nullptr){
            return true;
        }
        return false;
    }

    bool eliminarPorNombre(string nombreP) {
        if (PrimerElemento == nullptr) {
            cout << "La lista está vacía, no se puede eliminar." << endl;
            return false;
        }

        if (PrimerElemento->habilidad->nombre == nombreP) {
            HabilidadesPropias* temp = PrimerElemento;
            PrimerElemento = PrimerElemento->siguiente;
            delete temp;//no sabia que se liberaba la memoria con esto att aaron
            return true;
        }

        HabilidadesPropias* actual = PrimerElemento;
        while (actual->siguiente != nullptr && actual->siguiente->habilidad->nombre != nombreP) {
            actual = actual->siguiente;
        }
    
        if (actual->siguiente == nullptr) {
            cout << "no se encontró en la lista." << endl;
            return false;
        }
    
        HabilidadesPropias* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        delete temp;
        return true;
    }
    

    string toString(){
        stringstream ss;
        HabilidadesPropias *temp = PrimerElemento;
        if (temp == nullptr) {
            return "Sin Habilidades";
        }

        ss << "Lista de habilidades propias:\n";
        while (temp != nullptr) {
            ss << temp->toString() << " -> "; 
            temp = temp->siguiente;
        }
        ss << "NULL";  

        return ss.str();

    }
    
};
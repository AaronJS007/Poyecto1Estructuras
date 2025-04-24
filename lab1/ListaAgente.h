#include <iostream>
using namespace std;
#include "Agente.h"
class ListaAgente
{
public:
    Agente * PrimerElemento;
    Agente * UltimoElemento;
    ListaAgente(){
        PrimerElemento=nullptr;
        UltimoElemento=nullptr;
    }
    ~ListaAgente();

    bool AgregarAgente (string Pnombre, string Prol, int Pnivel_habilidad){
        try
        {
            Agente * nuevoAgente = new Agente(Pnombre,Prol,Pnivel_habilidad);
            if(PrimerElemento==nullptr){
                PrimerElemento=nuevoAgente;
                return true;
            }
            Agente * temp = PrimerElemento;
            while (temp->siguiente!=nullptr){
                temp=temp->siguiente;
            }
            temp->siguiente=nuevoAgente;
            return true;   
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
    }
    bool AgregarOd1(string Pnombre, string Prol, int Pnivel_habilidad){
        try
        {
            Agente * nuevoAgente = new Agente(Pnombre,Prol,Pnivel_habilidad);
            if (UltimoElemento==nullptr){
                PrimerElemento=nuevoAgente;
                UltimoElemento=nuevoAgente;
                return true;
            }
            nuevoAgente->anterior=UltimoElemento;
            UltimoElemento->siguiente=nuevoAgente;
            UltimoElemento=nuevoAgente;
            return true;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            cout << "No se agrego el agente\n";
            return false;
        }
                
    }

    Agente * buscarxNombre(string nombreP){
        Agente* temp = PrimerElemento;
    
        while (temp != nullptr) {  
            if (temp->nombre == nombreP) {
                return temp;  
            }
            temp = temp->siguiente;
        }
    
        return nullptr;
    }

    bool AgregarHabilidad(string nombrep, Habilidad * pHabilidad){
        Agente * temp = PrimerElemento;
        do{
            if(temp->nombre==nombrep){
                if(temp->propias->agregar(pHabilidad)){
                    cout << "Se agrego correctamente"<< endl;
                    return true;
                }
            }
        } while (temp!=nullptr);
        return false;
    }

    bool eliminaraxNombre(string pNombre){
        if(PrimerElemento==nullptr){
            cout << "No hay elementos \n";
            return false;
        }
        if (PrimerElemento->nombre==pNombre){
            if(PrimerElemento->siguiente==nullptr){
                delete PrimerElemento;
                PrimerElemento=nullptr;
                UltimoElemento=nullptr;
                return true;
            }
            PrimerElemento=PrimerElemento->siguiente;
            delete PrimerElemento->anterior;
            return true;
        }
        Agente * temp = PrimerElemento;

        while (temp!=nullptr){
            temp=temp->siguiente;
            if (temp == nullptr){
                cout << "El elemento no existe en la lista de agentes \n";
                return false;
            }
            if(temp->nombre==pNombre){
                temp->anterior->siguiente=temp->siguiente;
                temp->siguiente->anterior=temp->anterior;
                delete temp;
                return true;
            }
        }
        return false;
    }

    bool modificarNivel(string nombreP, int n){
        if (PrimerElemento == nullptr) {
            return false;
        }  
        Agente* temp = PrimerElemento;
        while (temp != nullptr) {  
            if (temp->nombre == nombreP) {
                temp->nivel_habilidad = n; 
                return true;  
            }
            temp = temp->siguiente;
        }
        return false;      
    }

    Agente * AgenteConMayorNivel(){
        if(PrimerElemento==nullptr){
            return nullptr;
        }
        Agente*temp=PrimerElemento;
        Agente*mayor=PrimerElemento;
        while (temp!=nullptr){
            temp=temp->siguiente;
            if(mayor->nivel_habilidad < temp->nivel_habilidad){
                mayor=temp;
            }
        }
        return mayor;
    }

    string toString(){
        stringstream ss;
        Agente *temp = PrimerElemento;
        if (temp == nullptr) {
            return "No hay agentes para mostrar";
        }

        ss << "Lista de Agentes:\n";
        while (temp != nullptr) {
            ss << temp->toString(); 
            temp = temp->siguiente;
        }  

        return ss.str();

    }

};



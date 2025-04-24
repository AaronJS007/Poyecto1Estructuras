#include "estudiante.h"

class ListaEstudiantes
{
private:
    estudiante * primerElemento;
public:
    ListaEstudiantes(){
        primerElemento=nullptr;
    };
    int tamanno(){
        if (primerElemento==nullptr){
            return 0;
        }
        int contador=1;
        estudiante * temp = primerElemento;
        while (temp->siguiente!=nullptr){
            temp=temp->siguiente;
            contador++;
        }
        return contador;
    }


    void imprimirEstudiante(estudiante*temp){
        cout << "*****************************************************************\n";
        cout << "|| Nombre:" << temp->nombre << " || ID:" << temp->id << "\n";
        cout << "Notas:\n";
        cout << "|| Matematica:" << temp->calificaciones[0] << " || Espeñol:" << temp->calificaciones[1] << " || Estudios sociales:" << temp->calificaciones[2] << "\n";
        cout << "|| Educacion civica:" << temp->calificaciones[3] << " || ciencias:" << temp->calificaciones[4] << "\n";
    }
    /*
agregarEstudiante: para agregar un nuevo estudiante a la lista, solicitando al usuario que
ingrese su nombre, número de identificación y calificaciones.
    */
    bool agregar(string nombre,int id, int cali[5]){
        
        try
        {
            estudiante * Nuevo = new estudiante(id,nombre,cali);
            if (primerElemento==nullptr){
                primerElemento=Nuevo;
                return true;
            }
            estudiante * temp = primerElemento;
            while (temp->siguiente!=nullptr){
                temp=temp->siguiente;
            }
            temp->siguiente=Nuevo;
            return true;
        }catch(const std::exception& e){
            std::cerr << e.what() << '\n';
            cout << "No se agrego el estudiante";
            return false;
        }
        
    }
    /*
    mostrarEstudiantes: para mostrar la información de todos los estudiantes en la lista,
incluyendo sus calificaciones.
    */
   bool mostrarEstudiantes(){
        if (primerElemento==nullptr){
            return false;
        }
        estudiante * temp = primerElemento;
        cout << "                   Tabla de estudiantes \n";
        do{
            imprimirEstudiante(temp);
            temp=temp->siguiente;
        } while (temp!=nullptr);
        return true;
   }

   estudiante * buscarPorID(int id){
    estudiante * temp = primerElemento;
    while (temp!=nullptr){
        if (id==temp->id){
            return temp;
        }
        temp=temp->siguiente;
    }
    //cout << "no hay ningun estudiante con el Id: " << id;
    return nullptr;
    
   }

/*
buscarEstudiante: para buscar un estudiante por su número de identificación y mostrar su
información.
*/
   bool mostrarEstudiante(int id){
    estudiante * temp = buscarPorID(id);
    if (temp==nullptr){
        return false;
    }
    imprimirEstudiante(temp);
    return true;
    }
    ~ListaEstudiantes();
};
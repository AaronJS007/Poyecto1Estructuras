#include <iostream>
using namespace std;
struct estudiante{
    
    int id;
    string nombre;
    int calificaciones[5];
    estudiante * siguiente;

    estudiante(int idp,string nombrep){
        id=idp;
        nombre=nombrep;
        for (int i = 0; i < 5; i++) {
            calificaciones[i] = 0;
        }
        siguiente = nullptr;
    }
    estudiante(int idp,string nombrep,int calificacionesp[]){
        id=idp;
        nombre=nombrep;
        for (int i = 0; i < 5; i++) {
            calificaciones[i] = calificacionesp[i];
        }
        siguiente = nullptr;
    }
    
    ~estudiante();
};

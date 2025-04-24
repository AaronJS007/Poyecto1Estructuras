#include <iostream>
using namespace std;
struct estudiante{

    string nombre;
    int carnet;

    estudiante *sig;
    estudiante *ant;
    struct matricula *subListaM;


    estudiante(string n, int c){

        nombre = n;
        carnet = c;
        sig = NULL;
        ant = NULL;
        subListaM = NULL;

    }
};

//Inserta estudiantes en un lista doble
void insertarInicioEstudiantes(string n, int c){

    struct estudiante *nuevoEst = new estudiante(n,c);

    nuevoEst -> sig = primeroE;

    if(primeroE != NULL)
        primeroE -> ant = nuevoEst;

    primeroE = nuevoEst;

}

void imprimirEstudiantes(){

    struct estudiante *temp = primeroE;

    while(temp != NULL){

        cout << endl << "Nombre: " << temp -> nombre << "\t" << "Carnet: "<< temp -> carnet;

        temp = temp -> sig;

    }
}
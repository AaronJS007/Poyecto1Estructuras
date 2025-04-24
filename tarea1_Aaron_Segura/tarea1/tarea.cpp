#include<iostream>
#include "ListaEstudiantes.h"
#include <limits>
using namespace std;

ListaEstudiantes * miLista = new ListaEstudiantes();

int obtenerEntero(string mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Error: Ingrese solo números enteros.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
        } else {
            return numero;
        }
    }
}

void menuAgregar(){
    string nombre="",salir="-1";
    int id=0;
    int materias[]={0,0,0,0,0};
    while (true){
    
    cout << "                   agregar estudiante \n";
    cout << "*****************************************************************\n";
    cout << "Digite el Nombre: ";
    cin >> nombre;
    id=obtenerEntero("Digite el numero de cedula: ");
    cout << "Digite las notas del estudiante \n";
    string nombresMaterias[] = {"Matematicas", "Español", "Estudios Sociales", "Educacion Civica", "Ciencias"};

    for (int i = 0; i < 5; i++) {
        do {
            materias[i] = obtenerEntero(nombresMaterias[i] + ": ");

            if (materias[i] < 0 || materias[i] > 100) {
                cout << "Error: La nota debe estar entre 0 y 100. Intente de nuevo.\n";
            }

        } while (materias[i] < 0 || materias[i] > 100);
    }
/*  cout << "Ingles: ";
    cin >> materias[5];*/
    if (miLista->agregar(nombre,id,materias)){
        cout << "Alumno Agregado correctamente\n";
    }else{
        cout << "No se pudo agregar el alumno\n";
    }
    cout << "*****************************************************************\n";
    cout << "salir (0) \nAgregar alumno(1) \n";
    cin >> salir;
    if (salir=="0"){
        return;
    }
    }
    
    
}

void MostrarTodos(){
        if(!miLista->mostrarEstudiantes()){
            cout << "No hay elementos para mostrar \n";
        }
}

void MostrarEstudiante(){
    int id=0;
    cout << "*****************************************************************\n";
    id=obtenerEntero("cerrar(0) \nDigite el numero de cedula del estudiante: ");
    if(id==0){
        return;
    }else{

    }
    if(!miLista->mostrarEstudiante(id)){
        cout << "No se encontro el estudiante con cedula: "<< id<<"\n";
    }
    cout << "*****************************************************************\n";
}

void menuInicial(){
    string cierre = "-1";
    while (true){
        cout << "                        Menu Principal \n";
        cout << "***************************************************************** \n";
        cout << "agregar (1) \nmostrar todos (2)\nbuscar por cedula (3)\nsalir (0)\n";
        cin >> cierre;
        cout << "***************************************************************** \n";
        if (cierre=="0"){
            return;
        }
        
        if(cierre=="1"){
            menuAgregar();
        }else{
            if(cierre=="2"){
                MostrarTodos();
            }else{
                if(cierre=="3"){
                    MostrarEstudiante();
                }
                
            }        
        }
        
        cout << "*****************************************************************\n";
    }
}

int main(){
    menuInicial();
    return 0;
}
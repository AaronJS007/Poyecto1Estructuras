#include<iostream>
#include "ListaAgente.h"
#include "ListaHabilidades.h"
#include "Habilidad.h"
#include <limits>
using namespace std;

ListaAgente * LsAgentes = new ListaAgente();
ListaHabilidades * LsHabilidades = new ListaHabilidades();

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
void AgregarAgente(){
    string nombre,rol;
    int nivel=0;
    cout << "                   Agregar Agente \n";
    cout << "*****************************************************************\n";
    cout << "Digite el Nombre: ";
    cin >> nombre;
    cout << "Digite el rol del agente: ";
    cin >> rol;
    nivel=obtenerEntero("Digite el Nivel: ");
    if(LsAgentes->AgregarOd1(nombre,rol,nivel)){
        cout << "Agente agregado";
    }
}

void crearHabilidad(){
    string nombreAgente,nombre, tipo;
    cout << "Digite el nombre del agente para agregarle la habilidad: ";
    cin >> nombreAgente;
    cout << "Digite el nombre de la habilidad: "<< endl;
    cin >> nombre;
    cout << "Digite el tipo de la habilidad: "<< endl;
    cin >> tipo;
    if(LsAgentes->AgregarHabilidad(nombreAgente,LsHabilidades->insertar(nombre,tipo))){
        cout << "No se encontro el Agente"<< endl;
    }    
}

void buscarAgente() {
    string nombre;
    cout << "Digite el nombre del Agente: "<< endl;
    cin >> nombre;
    Agente * temp = LsAgentes->buscarxNombre(nombre);
    cout << temp->toString();
}

void eliminarAgente() {
    string nombre;
    cout << "Digite el nombre del Agente: "<< endl;
    cin >> nombre;
    Agente * temp = LsAgentes->buscarxNombre(nombre);
    while (!temp->propias->estavacio()){
        nombre=temp->propias->getNombrePrimerElemento();
        if(temp->propias->eliminarPorNombre(nombre) && LsHabilidades->eliminarPorNombre(nombre) && LsAgentes->eliminaraxNombre(nombre)){
            cout << "Se elimino correctamente"<< endl;
        }else{
            cout << "No se pudo eliminar"<<endl;
        }
    }
}

void eliminarHabilidad() {
    string nombreAgente,nombreHabilidad;
    cout << "Digite el nombre del agente: "<< endl;
    cin >> nombreAgente;
    cout << "Digite el nombre de la Habilidad: "<< endl;
    cin >> nombreHabilidad;

    Agente* temp = LsAgentes->buscarxNombre(nombreAgente);
    if(temp->propias->eliminarPorNombre(nombreHabilidad)){
        cout << "Elemento eliminado de la lista de habilidades del personaje \n";
    }else{
        cout << "No se elimino el elemento \n";
    }
}

void modificarNivelHabilidad() {
    int nivel;
    string nombre;
    cout<< "Digite el nombre del personaje: \n";
    cin >> nombre; 
    nivel=obtenerEntero("Digite en nuevo nivel de la habilidad");
    if(LsAgentes->modificarNivel(nombre,nivel)){
        cout<<"se modifico el agente\n";
    }
}

void mostrarEstadisticas() {
    cout << "El agente con mayor nivel de habilidad es: "<< LsAgentes->AgenteConMayorNivel()->nombre;
}   

void menuInicial(){
    string cierre = "-1";
    while (true){
        int opcion;
        cout << "\n\nMenu:" << endl;
        cout << "1. Agregar agente" << endl;
        cout << "2. Agregar nueva habilidad"<< endl;
        cout << "3. Buscar agente" << endl;
        cout << "4. Eliminar agente" << endl;
        cout << "5. Eliminar habilidad de un agente" << endl;
        cout << "6. Modificar nivel de habilidad" << endl;
        cout << "7. Mostrar estadísticas" << endl;
        cout << "8. Mostrar todos los agentes" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cout << "\n";
        
        switch (opcion) {
            case 1: AgregarAgente(); break;
            case 2: crearHabilidad(); break;
            case 3: buscarAgente(); break;
            case 4: eliminarAgente(); break;
            case 5: eliminarHabilidad(); break;
            case 6: modificarNivelHabilidad(); break;
            case 7: mostrarEstadisticas(); break;
            case 8: cout << LsAgentes->toString(); break;
            case 0: cout << "Saliendo..." << endl; return;
            default: cout << "Opción no válida, intente de nuevo." << endl;
        }
    }
}








int main(){
    menuInicial();
    return 0;
}

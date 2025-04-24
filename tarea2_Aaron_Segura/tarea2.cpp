#include<iostream>
#include "listaEntrenadores.h"
#include "listaBatallas.h"
#include <limits>
using namespace std;

ListaEntrenadores * LsEntrenadores = new ListaEntrenadores();
 listaBatallas * LsBatallas = new listaBatallas();


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

void AgregarEntrenador(){
    int id;
    string nombre;
    int nivel;
    id=obtenerEntero("Digite el Identificador del entrenador: ");
    cout << "Digite el nombre del entrenador: "<< endl;
    cin >>nombre;
    nivel=obtenerEntero("Digite el nivel: ");
    if(LsEntrenadores->AgregarEntrenador(id,nombre,nivel)){
        cout << "Se agrego el entrenador"<< endl;
    }else{
        cout << "no se pudo agregar el entrenador" << endl;
    }
}
void AgregarPokemones(){
    int id, nivel;
    string nombre;
    id=obtenerEntero("Digite el id del entrenador: ");
    cout << "Digite el nombre del pokemon: " << endl;
    cin >> nombre;
    nivel=obtenerEntero("Digite el nivel del pokemon");
    if(LsEntrenadores->BuscarEntrenador(id)->pokemones->AgregarPokemon(nombre,nivel)){
        cout << "Se Agrego el pokemon";
    }else{
        cout << "No se encontro el Entrenador"<< endl;
    }
}

void ModificarEntrenador(){
    int id, nivel;
    id = obtenerEntero("Digite el identificador del entrenador");
    nivel = obtenerEntero("Digite el nuevo nivel del entrenador");
    if(LsEntrenadores->modificarNivelEntrenador(id,nivel)){
        cout << "Se modifico con exito";
    }else{
        cout << "No se encontro el entrenador"<< endl;
    }
}
void EliminarEntrenador(){
    int id;
    id = obtenerEntero("Digite el identificador del entrenador");
    if(LsEntrenadores->eliminarPorID(id)){
        cout << "Se Elimino con exito";
    }else{
        cout << "No se encontro el entrenador"<< endl;
    }
}

void menuGEntrenador(){
    string cierre = "-1";
    while (true){
        int opcion;
        cout << "\n\nMenu:" << endl;
        cout << "1. Agregar Entrenador" << endl;
        cout << "2. Agregar nuevo pokemon"<< endl;
        cout << "3. Modificar nivel de un Entrenador" << endl;
        cout << "4. Eliminar entrenador" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cout << "\n";
        
        switch (opcion) {
            case 1: AgregarEntrenador(); break;
            case 2: AgregarPokemones(); break;
            case 3: ModificarEntrenador(); break;
            case 4: EliminarEntrenador(); break;
            case 0: cout << "Regresando al menu principal" << endl; break;
            default: cout << "Opción no válida, intente de nuevo." << endl;
        }
    }
}

void ModificarPokemon(){
    int Id, nivel;
    string nombre; 
    Id=obtenerEntero("Digite el identificador del entrenador: ");
    cout << "Digite el nombre del pokemon: "<< endl;
    cin >> nombre;
    nivel=obtenerEntero("Digite el nuevo nivel: ");
    if(LsEntrenadores->BuscarEntrenador(Id)->pokemones->modificarPokemon(nombre,nivel)){
        cout << "se Modifico con exito";
    }else{
        cout << "no se pudo modificar" << endl;
    }
}
bool EliminarPokemon(){
    int Id;
    string nombre; 
    Id=obtenerEntero("Digite el identificador del entrenador: ");
    cout << "Digite el nombre del pokemon: "<< endl;
    cin >> nombre;
    if(LsEntrenadores->BuscarEntrenador(Id)->pokemones->eliminarPokemon(nombre)){
        cout << "se Elimino con exito";
        return true;
    }
    cout << "no se pudo Eliminar" << endl;
    return false;
}

void menuGPokemon(){
    string cierre = "-1";
    while (true){
        int opcion;
        cout << "\n\nMenu:" << endl;
        cout << "1. Modificar nivel pokemon" << endl;
        cout << "2. Eliminar pokemon" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cout << "\n";
        
        switch (opcion) {
            case 1: ModificarPokemon(); break;
            case 2: EliminarPokemon(); break;
            case 0: "Saliendo al menu principal..."; break;
            default: cout << "Opción no válida, intente de nuevo." << endl;
        }
    }
}

void RegistrarBatalla(){
    int id1,id2;
    id1=obtenerEntero("Digite el nombre del Entrenador 1");
    id2=obtenerEntero("Digite el nombre del Entrenador 2");
    if(LsBatallas->NuevaBatalla(LsEntrenadores->BuscarEntrenador(id1),LsEntrenadores->BuscarEntrenador(id2))){
        cout << "Se agrego con exito"<< endl;
    }else{
        cout << "no se pudo registrar la batalla"<<endl;
    }
};
void ListarBatallas(){
    cout << "Listando Batallas: "<< endl;
    LsBatallas->listarBatallas();
    cout << endl;
}

void menuGestorBatallas(){
    string cierre = "-1";
    while (true){
        int opcion;
        cout << "\n\nMenu:" << endl;
        cout << "1. Registrar una Batalla" << endl;
        cout << "2. Listar Batallas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cout << "\n";
        
        switch (opcion) {
            case 1: RegistrarBatalla(); break;
            case 2: ListarBatallas(); break;
            case 0: cout << "Saliendo al menu principal..."; break;
            default: cout << "Opción no válida, intente de nuevo." << endl;
        }
    }
}
void estadisticas(){
    cout << "Cantidad Total de Entrenadores: " << LsEntrenadores->contador <<endl;
    cout << "Cantidad Total de Pokemones: " << LsEntrenadores->TotalPokemones() <<endl;
    cout << "Total de batallas regitradas"<< LsBatallas->contador <<endl;
    cout << "Estadísticas de entrenadores: " << endl;
    LsEntrenadores->mostrarEntrenadores();    
}

void menuInicial(){
    string cierre = "-1";
    while (true){
        int opcion;
        cout << "\n\nMenu:" << endl;
        cout << "1. Gestor de entrenadores" << endl;
        cout << "2. Gestor de pokemon"<< endl;
        cout << "3. Gestor de batallas" << endl;
        cout << "4. Estadisticas del sistema" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cout << "\n";
        
        switch (opcion) {
            case 1: menuGEntrenador(); break;
            case 2: menuGPokemon(); break;
            case 3: menuGestorBatallas(); break;
            case 4: estadisticas(); break;
            case 0: cout << "Saliendo..." << endl; return;
            default: cout << "Opción no válida, intente de nuevo." << endl;
        }
    }
}








int main(){
    menuInicial();
    return 0;
}


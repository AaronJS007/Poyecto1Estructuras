#include <iostream>
using namespace std;
struct curso{

    string nombre;
    string codigo;
    int creditos;

    curso *sig;

    curso (string n, string cod, int cred){

        nombre = n;
        codigo = cod;
        creditos = cred;
        sig = NULL;

    }
};

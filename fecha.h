#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

struct fecha{

    int dia,mes,anno;

    fecha(int pDia, int pMes, int pAnno){
        dia=pDia;
        mes=pMes;
        anno=pAnno;
    }
    ~fecha();

};


#endif
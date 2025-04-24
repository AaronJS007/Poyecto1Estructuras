#include <iostream>
using namespace std;
struct matricula{

    matricula *sig;
    struct curso *enlace;

    matricula(struct curso *c){

        sig= NULL;
        enlace = c;

    }
};

#ifndef CONEJO_H
#define CONEJO_H
#include <stdlib.h>     
#include <time.h> 
/*
    clase de cada individuo contiene la
    informacion minima para que cada conejo
    funcione por su cuenta
*/

class conejo 
{
private:
    char forma; // el caracter que representara al conejo
    int vel; //su velocidad
public:
    conejo(); //constructor por defecto (esta cosa esta definida como un constructor que no requiera nada para llamarse)
    conejo(char,int); //constructor personalizable
    ~conejo();
    int get_v();
    char get_f();

    int correr(); // funcion para ver cuanto avanzaria el conejo
};




#endif

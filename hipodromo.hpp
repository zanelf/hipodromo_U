#ifndef HIPODROMO_H
#define HIPODROMO_H
#include "conejo.hpp"
#include <stdlib.h>     
#include <time.h> 

#define max_comps 100

/*
clase mayor que gestionara la resolucion de la
carrera en si, esta clase deberia gestionar toda la carrera

*/

class hipodromo
{
private:
    int cants; //cantidad de concursantes
    conejo competidores[max_comps]; // el arreglo de los competidores, con su velocidad y su figura 
    int pos[max_comps]; //arreglo que guardara la posicion actual de los competidores
    int podio; //guarda al competidor que vaya a la cabeza
    int meta; //posicion de victoria 
public:
    hipodromo(); //constructor rapido para llegar y arrancar
    hipodromo(int,int); //constructor personalizado
    ~hipodromo(); //si las cantidades son negativas no puedes hacer nada


    int get_cants();
    int get_pos(int);
    int get_podio();
    conejo mostrar_com(int);
    int get_meta();
    
    void set_cants(int);
    void set_meta(int);

    void carrera(int); //funcion que hace que un competidor corra
    bool ganador(int); //revisa si el conejo de la posicion pedida paso la meta o no
    void nueva_carrera(); 
};


#endif
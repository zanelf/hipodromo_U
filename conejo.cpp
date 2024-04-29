#include"conejo.hpp"

conejo::conejo(){ //si no quieres pensarla creara un conejo con una forma aleatoria entre muchas opciones
    this->forma = rand()%79 + 47; //%27 + 97
    this->vel = rand()%4+2;

}

conejo::conejo(char forma, int vel){ //constructor comun y silvestre
    this->forma = forma;
    this->vel = vel;
}   



conejo::~conejo(){ 
    forma = '\0'; //forma vacia
    vel = 0; 


    
}

char conejo::get_f(){
    return forma; //entrega la forma del personaje
}

int conejo::get_v(){
    return vel; //entrega la velocidad del personaje
}

int conejo::correr(){     
    /*
    para hacer mas dinamica la carrera en vez de 
    llamar a la velocidad se crea una variable aux
    que entrega un valor aleatorio extra para la velocidad 
    */
    int aux = ((rand()%vel) - vel/2);  // el rango de aux puede ir entre la mitad de la velocidad hasta casi la mitad
    //return aux+vel; //la velocidad particular a la que se desplazara
    return rand()%2;
}
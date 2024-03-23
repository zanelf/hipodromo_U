#include"hipodromo.hpp"
#include<iostream>

hipodromo::hipodromo(){
    this->cants = 5;
    this->podio = 1;
    this->meta = 100;
    for(int i = 0;i<cants;i++){
        this->competidores[i] = conejo();
        pos[i] = 0;
    }
}

hipodromo::hipodromo(int cants,int meta){
    this->cants = cants;
    this->podio = 1;    
    this->meta = meta;
    for(int i = 0;i<cants;i++){
        competidores[i] = conejo();
        pos[i] = 0;
    }
}

hipodromo::~hipodromo()
{
    this->cants = -1;
}

//getters genericos
int hipodromo::get_cants(){
    return cants;
}
int hipodromo::get_pos(int i){
    return pos[i];
}
int hipodromo::get_podio(){
    return podio;
}


conejo hipodromo::mostrar_com(int i){ //un getter para todo un conejo
    return competidores[i];
}



void hipodromo::carrera(int i){  
    /*
        esta funcion hace que un competidor corra de forma invididual.
        lo hace llamando a la funcion correr de cada conejo y actualiza su posicion
        luego de eso revisara si ahora este conejo va a la cabeza o si paso la linea de meta,  
        si llega a la linea de meta retorna un true y si no un false
    */
    pos[i]+=competidores[i].correr();
    if(pos[i]> pos[podio]){
        podio = i;
    }
}

bool hipodromo::ganador(int i){
    if(pos[i] >= meta)
        return true;
    else
        return false;
}

#include"hipodromo.hpp"
#include<iostream>

hipodromo::hipodromo(){
    this->cants = 5;
    this->podio = 1;
    this->meta = 100;
    this->num_vueltas = 3;
    for(int i = 0;i<cants;i++){
        this->competidores[i] = conejo();
        pos[i] = 0;
        vueltas[i] = 0;
    }
}

hipodromo::hipodromo(int cants,int meta, int num_vueltas){
    this->cants = cants;
    this->podio = 1;    
    this->meta = meta;
    this->num_vueltas = num_vueltas;
    for(int i = 0;i<cants;i++){
        competidores[i] = conejo();
        pos[i] = 0;
        vueltas[i] = 0;
    }
}

hipodromo::~hipodromo()
{
    this->cants = -1;    for(int i = 0;i<cants;i++){
        competidores[i] = conejo();
        pos[i] = 0;
    }
}

//setters 
void hipodromo::set_cants(int nuevos){
    if(nuevos <= max_comps){
        if (nuevos>cants){
                int aux = nuevos-cants;
                for(int i = 0;i<aux;i++){
                    competidores[cants+i] = conejo();
                }
            }
            cants = nuevos;
    }
}

void hipodromo::set_meta(int meta){
    this->meta = meta;
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

int hipodromo::get_vuelta(int i){
    return vueltas[i];
}

int hipodromo:: get_num_vueltas(){
    return num_vueltas;
}

conejo hipodromo::mostrar_com(int i){ //un getter para todo un conejo
    return competidores[i];
}

int hipodromo::get_meta(){
    return meta;
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

void hipodromo::nueva_carrera(){
    for(int i = 0;i<cants;i++)
        pos[i] = 0;
    


}
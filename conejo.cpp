#include"conejo.hpp"

conejo::conejo(char forma, int vel){
    this->forma = forma;
    this->vel = vel;
}   

conejo::~conejo(){
    forma = '\0';
    vel = 0;
}

void conejo::C_vel(int v){
    vel = v;
}

char conejo::get_forma(){
    return forma;
}

int conejo::get_vel(){
    return vel;
}

float conejo::correr(){
    
    float aux = ((rand()%10) + 1); 
    return aux+vel;
}
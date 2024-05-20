#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <algorithm>
#include<vector>
using namespace std;


typedef struct{
    char forma; //como se ve
    int posicion; //cuanto a recorrido en una vuelta
    int vueltas; //cuantas vueltas a llevado
    bool completo;
}conejo;

vector<conejo> competidores; //vector con toda la informacion que sera almacenada
vector<conejo> podio;
int Lmeta=30; // distancia a la que estara la meta
int cantidad_vueltas = 3; //cantidad de vueltas necesarias para ganar



void aumentar_competidores(int cants){ // aumenta la cantidad de competidores

    if(cants >=0){ //verifica que sea un positivo
        for(int i = 0;i< cants;i++){ //crea un conejo auxiliar y lo agrega a la lista
            conejo aux;
            aux.forma = rand()%79 + 47;
            aux.posicion = 0;
            aux.vueltas = 0;
            aux.completo = false;
            competidores.push_back(aux); //lo agrega a la lista de los competidores
        }
    }
}

void reducir_competidores(int cants){
    if(cants >=0){
        for(int i = 0;i< cants;i++)
           competidores.pop_back();
    }
}

bool estado_competidor(int i){ //revisara si ya a completado la carrera
    if(competidores[i].vueltas > cantidad_vueltas-1 ){ //esta en la ultima vuelta?
        if(competidores[i].posicion >= Lmeta){ //llego a la meta?
            competidores[i].posicion = Lmeta+1; //el conejo se detiene un paso afuera de la meta
            return true; //si
        }else{
            return false; //no
        }
    }else{   //no llego a la ultima vuelta
        if(competidores[i].posicion >= Lmeta){ //llego a la meta? 
            competidores[i].vueltas = competidores[i].vueltas +1 ; //le agrega una vuelta al competidor 
            competidores[i].posicion = 0;
        }
        return false; //no
    }

}



#endif

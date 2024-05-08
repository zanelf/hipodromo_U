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
int meta=30; // distancia a la que estara la meta
int cantidad_vueltas = 3; //cantidad de vueltas necesarias para ganar



void aumentar_competidores(int cants){ // aumenta la cantidad de competidores

    if(cants >=0){ //verifica que sea un positivo
        for(int i = 0;i< cants;i++){ //crea un conejo auxiliar y lo agrega a la lista
            conejo aux;
            aux.forma = rand()%79 + 47;
            aux.posicion = 0;
            aux.vueltas = 1;
            competidores.push_back(aux);
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
    if(competidores[i].vueltas == cantidad_vueltas ){
        if(competidores[i].posicion >= meta){
            return true;
        }else{
            return false;
        }
    }else{
        if(competidores[i].posicion >= meta){
            competidores[i].vueltas = competidores[i].vueltas +1 ;
            competidores[i].posicion = 0;
        }
        return false;
    }

}



#endif

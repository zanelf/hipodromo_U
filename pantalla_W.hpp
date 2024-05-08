#ifndef MENU_H
#define MENU_H
#include "sistema.hpp"
#include<stdio.h>
#include<iostream>
#include <conio.h> 
#include <windows.h>

using namespace std;

void interaccion_competidores();
void ajuste_meta();
void ajuste_vueltas();
void iniciar_carrera();

void ventana(){
    int op;
    do{
        std::cout<<"\t\t\t\t\tCARRERAS DE CONEJOS\n";
        std::cout<<"\t\t\t 1. Iniciar carrera\n";
        std::cout<<"\t\t\t 2. cambiar cantidad de competidores\n";
        std::cout<<"\t\t\t 3. cambiar distancia de la meta\n";
        std::cout<<"\t\t\t 4. cambiar cantidad de vueltas\n";
        std::cout<<"\t\t\t 5. salir\n";
        cin>>op;

    }while(op<1 || op>5);
    switch (op)
    {
    case 1:
        iniciar_carrera();
        break;
    case 2:
        interaccion_competidores();
        break;
    case 3:
        ajuste_meta();
        break;
    case 4:
        ajuste_vueltas();
        break;
    case 5:
        cout<<"bye bye >(x)";
        break;
    }


}

void interaccion_competidores(){
    cout<<"actualmente tiene "<<competidores.size()<<"competidores\n";
    cout<<"que accion quiere realizar\n ";
    int op2;
    //verifica que elige entre las opciones entregadas
    do{
        cout<<"1.agregar competidores\n2.eliminar competidores\n3.volver";
        cin>>op2;
    }while(op2!=1 || op2!=2 || op2!=3);
    
    //en funcion de que elija agregara o quitara corredores
    int n; 
    switch (op2)
    {
    case 1:
        cout<<"cuantos miembros quiere agregar: ";
           cin>>n;
        aumentar_competidores(n);
        break;
    case 2:
        cout<<"cuantos miembros quiere eliminar: ";
        cin>>n;
        reducir_competidores(n);
        break;        
    }
    ventana();
}

void ajuste_meta(){
    cout<<"donde quiere ubicar la meta (ingrese un numero mayor a 10 para crear un cambio)\nactualmente la meta esta a "<<meta<<" metros\n\t\t";
    
    int n;
    cin>>n;    
    if(n >= 10){
        meta = n;
    }
    ventana();
}

void ajuste_vueltas(){
    cout<<"cuantas vueltas quiere que realicen los conejos\nactualmente los conejos realizaran "<<cantidad_vueltas<<"\n\t\t\t";
    int n;
    cin>>n;
    if(n > 0){
        cantidad_vueltas = n;
    }
    ventana();
}

void iniciar_carrera(){
    bool continua = true;
    do{
        for(int i = 0;i<competidores.size();i++){
            competidores[i].completo = estado_competidor(i); //revisa como va el corredor
            if(!competidores[i].completo){ //si no a completado su carrera avanza
                competidores[i].posicion += rand()%2;  
                continua = true; 
            }else{

                continua = false;
                podio.push_back(competidores[i]);
            }
        }
        cout<<"=============\n";
        
        Sleep(5);
    }while(continua);
    

    ventana();
}

#endif


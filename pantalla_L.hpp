#ifndef MENU_L
#define MENU_L
#include "sistema.hpp"
#include<iostream>
#include <ncurses.h>
#include <unistd.h>
#include<pthread.h>

using namespace std;

void interaccion_competidores();
void ajuste_meta();
void ajuste_vueltas();
void iniciar_carrera();

void ventana(){
    int op,entrada;
    do{
        attron(A_BOLD | A_UNDERLINE);
        mvprintw(3, 33, "CARRERAS DE CONEJOS");
        attroff(A_BOLD | A_UNDERLINE);
        mvprintw(5, 25, "1. Iniciar carrera");
        mvprintw(6, 25, "2. Cambiar cantidad de competidores");
        mvprintw(7, 25, "3. Cambiar distancia de la meta");
        mvprintw(7, 25, "4. cambiar cantidad de vueltas");
        mvprintw(8, 25, "5. Salir");
        mvprintw(11, 29, "Ingrese su opción: ");
        refresh();
        entrada=scanw("%d",&op);



    }while(entrada==FALSE || entrada==ERR || op<1 || op>5);
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
        mvprintw(13,25,"cerrando aplicacion");
        break;
    }


}

void interaccion_competidores(){
    erase();
    int op2;
    mvprintw(1,12,"actualmente tiene %d competidores",competidores.size());
    mvprintw(2,12;"que accion quiere realizar:");
    scanw("%d", &op2);

    //verifica que elige entre las opciones entregadas
    do{
        erase();
        mvprintw(1,4,"1.agregar competidores");
        mvprintw(2,4,"2.eliminar competidores");
        mvprintw(3,4,"3.volver");

        scanw();
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


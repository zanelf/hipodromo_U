#ifndef MENU_L
#define MENU_L

#include "sistema.hpp"
#include<iostream>
#include <ncurses.h>
#include <unistd.h>
#include<pthread.h>

using namespace std;

void interaccion_competidores();
void ajuste_Lmeta();
void ajuste_vueltas();
void iniciar_carrera();
void ventanaL();

void ventanaL(){
    erase();
    int op, entrada;
    do {
        attron(A_BOLD | A_UNDERLINE);
        mvprintw(3, 33, "CARRERAS DE CONEJOS");
        attroff(A_BOLD | A_UNDERLINE);
        mvprintw(5, 25, "1. Iniciar carrera");
        mvprintw(6, 25, "2. Cambiar cantidad de competidores");
        mvprintw(7, 25, "3. Cambiar distancia de la meta");
        mvprintw(8, 25, "4. cambiar cantidad de vueltas");
        mvprintw(9, 25, "5. Salir");
        mvprintw(11, 29, "Ingrese su opción: ");
        refresh();
        entrada = scanw("%d", &op);
    } while (entrada == FALSE || entrada == ERR || op < 1 || op > 5);
    
    switch (op) {
        case 1:
            pthread_t hilo;
            pthread_create(&hilo, NULL, iniciar_carrera, NULL);
            break;
        case 2:
            interaccion_competidores();
            break;
        case 3:
            ajuste_Lmeta();
            break;
        case 4:
            ajuste_vueltas();
            break;
        case 5:
            mvprintw(13, 25, "Cerrando aplicación");
            break;
    }
}

void interaccion_competidores(){
    erase();
    int op2,n;
    mvprintw(1,12,"actualmente tiene %lu competidores",competidores.size());
    mvprintw(2,12,"que accion quiere realizar:");
        mvprintw(4,16,"1.agregar competidores");
        mvprintw(5,16,"2.eliminar competidores");
        mvprintw(6,16,"3.volver\n");
        refresh();
    //verifica que elige entre las opciones entregadas
    do{
        n  = scanw("%d",&op2);
        refresh();
    }while(n ==FALSE || n==ERR || op2<1 || op2>3);
    //en funcion de que elija agregara o quitara corredores 
    switch (op2)
    {
    case 1:
        mvprintw(8,4,"cuantos miembros quiere agregar: ");
        scanw("%d",&n);
        refresh();
        aumentar_competidores(n);

        break;
    case 2:
        mvprintw(8,4,"cuantos miembros quiere eliminar: ");
           scanw("%d",&n);
           refresh();
        reducir_competidores(n);
        break;        
    default:
        break;
    }
    ventanaL();
}

void ajuste_Lmeta(){
    erase();
    mvprintw(1,12,"donde quiere ubicar la meta (ingrese un numero mayor a 10 para crear un cambio)");
    mvprintw(2,12,"actualmente la meta esta a %d metros",Lmeta);
    mvprintw(3,16,": ");
    refresh();
    int n,eror;
    eror = scanw("%d",&n);    
    if(n >= 10 && eror == 1 ){
        Lmeta = n;
    }
    ventanaL();
}

void ajuste_vueltas(){
    erase();
    mvprintw(1,12,"cuantas vueltas quiere que realicen los conejos");
    mvprintw(2,12,"actualmente los conejos realizaran %d vueltas",cantidad_vueltas);
    mvprintw(3,16,": ");
    refresh();
    int n,eror;
    eror = scanw("%d",&n);
    if(n > 0 && eror == 1 ){
        cantidad_vueltas = n;
    }
    ventanaL();
}

void iniciar_carrera(){
    while(!podio.empty()){ //vacia el podio
        podio.pop_back();
    }

int terminados;
    do{
       terminados = 0;
        erase();
        for(int i = 0;i<competidores.size();i++){ //corre a cada conejo 
            competidores[i].completo = estado_competidor(i); //revisa como va el corredor
            if(!competidores[i].completo){ //si no a completado su carrera avanza
                competidores[i].posicion += rand()%2;  
            }else{//si completo su carrera
                terminados++;
                podio.push_back(competidores[i]); //lo mete al podio
            }
            mvprintw(i,competidores[i].posicion,"%c",competidores[i].forma);
            mvprintw(i,Lmeta,"|");

                mvprintw(competidores.size()+1+i,4,"%c || distancia: %d || vueltas: %d || termino: %d",competidores[i].forma,competidores[i].posicion,competidores[i].vueltas,competidores[i].completo);
                mvprintw(competidores.size()*2+4,4,"han terminado %d de %ld & %d",terminados,competidores.size(), (terminados == competidores.size()));

        }
        refresh();
        usleep(10000);
    }while(terminados != competidores.size()); //cuando el podio tenga la misma cantidad de wueyes que competidores tiene la carrera para

    getch();
    ventanaL();
}

#endif
#ifndef MENU_L
#define MENU_L

#include "sistema.hpp"
#include<iostream>
#include <ncurses.h>
#include <unistd.h>
#include<pthread.h>
#include<stdlib.h>       //bibliotecas funciones estandar
using namespace std;

void interaccion_competidores();
void ajuste_Lmeta();
void ajuste_vueltas();
void iniciar_carrera();
void ventanaL();

void* hacer_correr_conejo(conejo * corredor);

pthread_mutex_t pantalla; 

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
            // completar mas tarde 
            iniciar_carrera();
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

        mvprintw(8,16,"por limitaciones de codigo favor de no modificar la cantidad de competidores");
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

    erase();
  pthread_mutex_init (&pantalla, NULL);     //inicializa variable pantalla tipo mutex


    int eror1,eror2,eror3,eror4,eror5;                        //para verificar error al crear el thread
    pthread_t idHilo1,idHilo2,idHilo3,idHilo4,idHilo5;                //identificador del thread hijo


        //inicializacion de los hilos y configuracion inicial 
        eror1=pthread_create(&idHilo1, NULL, &hacer_correr_conejo, &competidores[0]);
        eror2=pthread_create(&idHilo2, NULL, &hacer_correr_conejo, &competidores[1]);
        eror3=pthread_create(&idHilo3, NULL, &hacer_correr_conejo, &competidores[2]);
        eror4=pthread_create(&idHilo4, NULL, &hacer_correr_conejo, &competidores[3]);
        eror5=pthread_create(&idHilo5, NULL, &hacer_correr_conejo, &competidores[4]);

        pthread_join(idHilo1 , NULL);
        pthread_join(idHilo2 , NULL);
        pthread_join(idHilo3 , NULL);
        pthread_join(idHilo4 , NULL);
        pthread_join(idHilo5 , NULL);
       getch();

        pthread_mutex_destroy(&pantalla);      
    ventanaL();
}


void *hacer_correr_conejo(conejo * corredor){ // hace que un conejo empiece a correr por el campo
    do{
        pthread_mutex_lock(&pantalla);
        erase();
            corredor->completo = estado_competidor(corredor); //revisa como va el corredor
            if(!corredor->completo){ //si no a completado su carrera avanza
                corredor->posicion += rand()%2;  
            }

            mvprintw(corredor->carril,corredor->posicion,"%c",corredor->forma);
            mvprintw(corredor->carril,Lmeta,"|");

                mvprintw(competidores.size()+1+corredor->carril,4,"%c || distancia: %d || vueltas: %d || termino: %d",competidores[i].forma,competidores[i].posicion,competidores[i].vueltas,competidores[i].completo);
 
        
        refresh();
        usleep(10000);
        pthread_mutex_unlock(&pantalla);
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }while(!corredor->completo);

}

#endif
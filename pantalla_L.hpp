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
        mvprintw(8, 25, "4. Cambiar cantidad de vueltas");
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
    int op2, n;
    mvprintw(1, 12, "Actualmente tiene %lu competidores", competidores.size());
    mvprintw(2, 12, "¿Qué acción quiere realizar?");
    mvprintw(4, 16, "1. Agregar competidores");
    mvprintw(5, 16, "2. Eliminar competidores");
    mvprintw(6, 16, "3. Volver");
    refresh();

    do {
        scanw("%d", &op2);
    } while (op2 != 1 && op2 != 2 && op2 != 3);

    erase();
    switch (op2) {
        case 1:
            mvprintw(3, 4, "¿Cuántos miembros quiere agregar? ");
            scanw("%d", &n);
            aumentar_competidores(n);
            break;
        case 2:
            mvprintw(3, 4, "¿Cuántos miembros quiere eliminar? ");
            scanw("%d", &n);
            reducir_competidores(n);
            break;
    }
    ventanaL();
}

void ajuste_Lmeta(){
    mvprintw(0, 0, "Donde quiere ubicar la meta (ingrese un número mayor a 10 para crear un cambio)\nActualmente la meta está a %d metros\n", Lmeta);
    
    int n;
    scanw("%d", &n);    
    if(n >= 10){
        Lmeta = n;
    }
    ventanaL();
}

void ajuste_vueltas(){
    mvprintw(0, 0, "¿Cuántas vueltas quiere que realicen los conejos?\nActualmente los conejos realizarán %d vueltas\n", cantidad_vueltas);
    int n;
    scanw("%d", &n);
    if(n > 0){
        cantidad_vueltas = n;
    }
    ventanaL();
}

void iniciar_carrera(){
    bool continua = true;
    do {
        for (int i = 0; i < competidores.size(); i++) {
            competidores[i].completo = estado_competidor(i); // Revisa cómo va el corredor
            if (!competidores[i].completo) { // Si no ha completado su carrera, avanza
                competidores[i].posicion += rand() % 2;  
                continua = true; 
            } else {
                continua = false;
                podio.push_back(competidores[i]);
            }
        }
        cout << "=============\n";
        usleep(1000);
    } while (continua);

    ventanaL();
}

#endif
#include <ncurses.h>
#include <unistd.h>
#include "conejo.hpp"
#include "hipodromo.hpp"
#include "menu.hpp"
#include<iostream>
#include<pthread.h>

#ifdef MUTEX
pthread_mutex_t pantalla;
#endif


int main(){
    srand(time(NULL));
    //ejemplo simplificado de como funcionaria hipodromo

    menu ventana;
    initscr();
    
    ventana.imprimir_menu();

    getch();
    endwin();
   
    return 0;


}
#include "sistema.hpp"
#ifdef __linux__  //si no esta en linux ignorara lo que este adentro
    #include <ncurses.h>
    #include <unistd.h>
    #include<pthread.h>
    #include"pantalla_L.hpp"
#elif _WIN32
    #include"pantalla_W.hpp"    
#endif

#include<iostream>
#include <time.h> 
/* 
#ifdef MUTEX
pthread_mutex_t pantalla;
#endif

 */


int main(){
    srand(time(NULL));
    //ejemplo simplificado de como funcionaria hipodromo
    aumentar_competidores(5);
    Lmeta =70;
    cantidad_vueltas = 5;
#ifdef __linux__ 
    initscr();
    ventanaL();
    endwin();

#elif _WIN32

    ventana();

#else
#endif

    return 0;
}
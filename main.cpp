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
    aumentar_competidores(4);
    // Lanzar el hilo para iniciar la carrera
    std::thread carrera_thread(lanzar_iniciar_carrera);

    // Esperar un tiempo antes de finalizar la carrera
    std::this_thread::sleep_for(std::chrono::seconds(10));

    // Detener la carrera
    carrera_thread.join();
    
#ifdef __linux__ 
    initscr();
    ventanaL();
    endwin();

#elif _WIN32


    aumentar_competidores(4);

    ventana();

#else
#endif

    return 0;
}
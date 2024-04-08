#include <ncurses.h>
#include <unistd.h>
#include "conejo.hpp"
#include "hipodromo.hpp"
#include "menu.hpp"
#include<iostream>


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
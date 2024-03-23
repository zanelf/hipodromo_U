#include <ncurses.h>

#include "conejo.hpp"
#include "hipodromo.hpp"
#include<iostream>

int main(){
    srand(time(NULL));
    int comps = 3;
    hipodromo juego(comps,200);
    bool ganador = false;

    initscr();
    for(int i = 0;i<20;i++){
        erase();
        refresh();
        mvprintw(0,juego.carrera(0),"%c\n",juego.mostrar_com(0).get_f());
        mvprintw(1,juego.carrera(1),"%c\n",juego.mostrar_com(1).get_f());
        mvprintw(2,juego.carrera(2),"%c\n",juego.mostrar_com(2).get_f());
        
        getch();
         
    }
    endwin();
    return 0;
}
#include <ncurses.h>

#include "conejo.hpp"
#include "hipodromo.hpp"
#include<iostream>

int main(){
    srand(time(NULL));
    int comps = 3;
    int dist_meta = 120;
    hipodromo juego(comps,dist_meta);
    bool ganador = false;

    initscr();

        while (!ganador){
            erase();
            refresh();
            
            for(int i = 0;i<juego.get_cants();i++){ //prueba de concepto
                juego.carrera(i);
                ganador = juego.ganador(i);
                mvprintw(i,juego.get_pos(i),"%c",juego.mostrar_com(i).get_f());
                mvprintw(i,dist_meta,"=");
                if(ganador)
                    break;
            }
//        getch();



        usleep(300000);  
        }
    
    //std::cout<<"el ganador es\n\t\t"<<juego.mostrar_com(juego.get_podio()).get_f()<<" "<<juego.mostrar_com(juego.get_podio()).get_v()<<"\nel cual recorrio\n"<<juego.get_pos(juego.get_podio());
    
        
    endwin();
    return 0;

    
}
#include <ncurses.h>
#include <unistd.h>
#include "conejo.hpp"
#include "hipodromo.hpp"
#include<iostream>

int main(){
    srand(time(NULL));
    //ejemplo simplificado de como funcionaria hipodromo

    int comps = 8; //cantidad de competidores
    int dist_meta = 120; // distancia para decir que se llego a una meta
    hipodromo juego(comps,dist_meta); //carga las configuraciones dentro del juego
    bool ganador = false; //un verificador sobre si ya se gano

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
            //getch();
            usleep(200000);          
        }
    
        
    endwin();
    return 0;


}
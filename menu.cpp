#include "menu.hpp"
#include <ncurses.h>
#include "hipodromo.hpp"
#include <unistd.h>

menu::menu(){
    this->comps = 5;
    this->dist_meta = 120;
    this->ganador = false;
    this->juego = hipodromo(comps,dist_meta);
}

void menu::imprimir_menu() {
    int op,entrada;
		do {
            attron(A_BOLD | A_UNDERLINE);
            mvprintw(3, 33, "MENU");
            attroff(A_BOLD | A_UNDERLINE);
            mvprintw(5, 25, "1. Iniciar carrera");
            mvprintw(6, 25, "2. Cambiar cantidad de competidores");
            mvprintw(7, 25, "3. Cambiar distancia del hipodromo");
            mvprintw(8, 25, "4. Salir");
            mvprintw(11, 25, "Ingrese su opción: ");
            refresh();
            entrada=scanw("%d",&op);
		} while(entrada==FALSE || entrada==ERR || op<1 || op>4);
        switch(op){
			case 1:
                iniciar_carrera();
				break;
			case 2:
                cambiar_cantidad_competidores();
				break;
			case 3:
                cambiar_distancia_carrera();
				break;
			case 4:
				mvprintw(13,25,"fin de la aplicacion");
				break;
		}
}



void menu::iniciar_carrera() {
        juego.nueva_carrera();
        ganador = false;
        while (!ganador){ 
            erase();
            for(int i = 0;i<juego.get_cants();i++){ 
                juego.carrera(i);
                ganador = juego.ganador(i);
                mvprintw(i,juego.get_pos(i),"%c",juego.mostrar_com(i).get_f());
                mvprintw(i,dist_meta,"=");
                if(ganador)
                    break;
                refresh();
            }            
            usleep(200000);          
        }
        erase();
        mvprintw(5,16,"el ganador es el conejo %d:\n\t\t\t\t%c",juego.get_podio(),juego.mostrar_com(juego.get_podio()).get_f());

        getch();
        erase();
        imprimir_menu();

}
void menu::cambiar_cantidad_competidores() {
    erase();
    int nueva_cantidad;
    mvprintw(0, 0, "Ingrese la nueva cantidad de competidores: ");
    scanw("%d", &nueva_cantidad);
    juego.set_cants(nueva_cantidad);
    mvprintw(1, 0, "La cantidad de competidores ha sido cambiada a %d.", juego.get_cants());
    getch();
    erase();
    refresh();
    imprimir_menu();
}

void menu::cambiar_distancia_carrera() {
    erase();
    int nueva_distancia;
    mvprintw(0, 0, "Ingrese la nueva distancia del hipodromo: ");
    scanw("%d", &nueva_distancia);
    juego.set_meta(nueva_distancia);erase();
    mvprintw(1, 0, "La distancia del hipodromo ha sido cambiada a %d metros.",juego.get_meta());
    getch();
    erase();
    refresh();
    imprimir_menu();
}
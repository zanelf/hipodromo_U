#include "menu.hpp"
#include <ncurses.h>

void menu::imprimir_menu() {
    attron(A_BOLD | A_UNDERLINE);
    mvprintw(3, 33, "MENU");
    attroff(A_BOLD | A_UNDERLINE);
    mvprintw(5, 25, "1. Iniciar carrera");
    mvprintw(6, 25, "2. Cambiar cantidad de competidores");
    mvprintw(7, 25, "3. Cambiar distancia del hipodromo");
    mvprintw(8, 25, "4. Salir");
    mvprintw(11, 25, "Ingrese su opción: ");
    refresh();
}
void menu::iniciar_carrera() {
    // Este bucle se ejecutará hasta que haya un ganador
    while (!ganador) {
        erase(); // Borra la pantalla
        refresh(); // Actualiza la pantalla
        
        // Itera sobre cada competidor en la carrera
        for (int i = 0; i < juego.get_cants(); i++) {
            // Simula el avance del competidor en la carrera
            juego.carrera(i);
            
            // Verifica si este competidor ha ganado la carrera
            ganador = juego.ganador(i);
            
            // Imprime en la pantalla el símbolo del competidor en su posición actual
            mvprintw(i, juego.get_pos(i), "%c", juego.mostrar_com(i).get_f());
            
            // Imprime en la pantalla la línea de meta
            mvprintw(i, dist_meta, "=");
            
            // Si hay un ganador, sale del bucle
            if (ganador)
                break;
        }
       
        getch(); // Espera a que el usuario presione una tecla
        usleep(300000); // Espera durante 300 milisegundos antes de la próxima actualización
    }
    endwin(); // Termina el modo ncurses

void menu::cambiar_cantidad_competidores() {
    clear();
    int nueva_cantidad;
    mvprintw(0, 0, "Ingrese la nueva cantidad de competidores: ");
    scanw("%d", &nueva_cantidad);
    mvprintw(1, 0, "La cantidad de competidores ha sido cambiada a %d.", nueva_cantidad);
    refresh();
    getch(); // Esperar hasta que el usuario presione una tecla
}

void menu::cambiar_distancia_carrera() {
    clear();
    int nueva_distancia;
    mvprintw(0, 0, "Ingrese la nueva distancia del hipodromo: ");
    scanw("%d", &nueva_distancia);
    mvprintw(1, 0, "La distancia del hipodromo ha sido cambiada a %d metros.", nueva_distancia);
    refresh();
    getch();
}
#ifndef MENU_H
#define MENU_H
#include "hipodromo.hpp"

class menu {
    private:
        int comps ; //cantidad de competidores
        int dist_meta ; // distancia para decir que se llego a una meta
        hipodromo juego; //carga las configuraciones dentro del juego
        bool ganador ; //un verificador sobre si ya se gano

    public:
        menu();// Inicializar ncurses aquí si es necesario
        void imprimir_menu();// Implementa la función de imprimir menú
        void iniciar_carrera();// Implementa la función de iniciar carrera
        void cambiar_cantidad_competidores();// Implementa la función de cambiar cantidad de competidores
        void cambiar_distancia_carrera();// Implementa la función de cambiar distancia de carrera
    
};

#endif


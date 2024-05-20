#ifndef MENU_H
#define MENU_H

#include "sistema.hpp"
#include <iostream>
#include <conio.h> 
#include <windows.h>

using namespace std;

void interaccion_competidores();
void ajuste_meta();
void ajuste_vueltas();
void iniciar_carrera();
void ventana();

void ventana() {
    int op;
    do {
        cout << "\t\t\t\t\tCARRERAS DE CONEJOS\n";
        cout << "\t\t\t 1. Iniciar carrera\n";
        cout << "\t\t\t 2. Cambiar cantidad de competidores\n";
        cout << "\t\t\t 3. Cambiar distancia de la meta\n";
        cout << "\t\t\t 4. Cambiar cantidad de vueltas\n";
        cout << "\t\t\t 5. Salir\n";
        cin >> op;

    } while (op < 1 || op > 5);
    switch (op) {
    case 1:
        iniciar_carrera();
        break;
    case 2:
        interaccion_competidores();
        break;
    case 3:
        ajuste_meta();
        break;
    case 4:
        ajuste_vueltas();
        break;
    case 5:
        cout << "bye bye >(x)";
        break;
    }
}

void interaccion_competidores() {
    cout << "Actualmente tiene " << competidores.size() << " competidores\n";
    cout << "¿Qué acción quiere realizar?\n";
    int op2;
    // Verifica que elige entre las opciones entregadas
    do {
        cout << "1. Agregar competidores\n2. Eliminar competidores\n3. Volver\n";
        cin >> op2;
    } while (op2 != 1 && op2 != 2 && op2 != 3);

    // En función de lo que elija, agregará o quitará corredores
    int n;
    switch (op2) {
    case 1:
        cout << "¿Cuántos miembros quiere agregar: ";
        cin >> n;
        aumentar_competidores(n);
        break;
    case 2:
        cout << "¿Cuántos miembros quiere eliminar: ";
        cin >> n;
        reducir_competidores(n);
        break;
    }
    ventana();
}

void ajuste_meta() {
    cout << "¿Dónde quiere ubicar la meta (ingrese un número mayor a 10 para crear un cambio)?\n";
    cout << "Actualmente la meta está a " << Lmeta << " metros\n";
    
    int n;
    cin >> n;    
    if (n >= 10) {
        Lmeta = n;
    }
    ventana();
}

void ajuste_vueltas() {
    cout << "¿Cuántas vueltas quiere que realicen los conejos?\n";
    cout << "Actualmente los conejos realizarán " << cantidad_vueltas << " vueltas\n";
    int n;
    cin >> n;
    if (n > 0) {
        cantidad_vueltas = n;
    }
    ventana();
}

void iniciar_carrera() {
    bool continua = true;
    do {
        for (int i = 0; i < competidores.size(); i++) {
            competidores[i].completo = estado_competidor(i); // Revisa cómo va el corredor
            if (!competidores[i].completo) { // Si no ha completado su carrera, avanza
                competidores[i].posicion += rand() % 2;  
                continua = true; 
            } else {
                continua = false;
                podio.push_back(competidores[i]);
            }
        }
        cout << "=============\n";
        Sleep(5000);
    } while (continua);

    ventana();
}

#endif 
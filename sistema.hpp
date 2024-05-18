#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <algorithm>
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

typedef struct {
    char forma; 
    int posicion; 
    int vueltas; 
    bool completo;
} conejo;

vector<conejo> competidores;
vector<conejo> podio;
int Lmeta = 30; 
int cantidad_vueltas = 3; 

std::mutex mtx; // Mutex global para sincronización

void estadoCarrera(const vector<conejo>& conejos) {
    std::lock_guard<std::mutex> lock(mtx);
    for (const auto& conejo : conejos) {
        std::cout << "Conejo " << conejo.forma << ": Vuelta " << conejo.vueltas 
                  << ", Posición " << conejo.posicion << std::endl;
    }
}

bool estado_competidor(int i) {
    if (competidores[i].vueltas == cantidad_vueltas) {
        if (competidores[i].posicion >= Lmeta) {
            return true;
        } else {
            return false;
        }
    } else {
        if (competidores[i].posicion >= Lmeta) {
            competidores[i].vueltas++;
            competidores[i].posicion = 0;
        }
        return false;
    }
}

void iniciar_carrera() {
    bool continua = true;
    do {
        continua = false;
        for (int i = 0; i < competidores.size(); i++) {
            {
                std::lock_guard<std::mutex> lock(mtx);
                competidores[i].completo = estado_competidor(i); // Revisa cómo va el corredor
                if (!competidores[i].completo) { // Si no ha completado su carrera, avanza
                    competidores[i].posicion += rand() % 2;
                    continua = true;
                } else if (competidores[i].vueltas >= cantidad_vueltas && find(podio.begin(), podio.end(), competidores[i]) == podio.end()) {
                    podio.push_back(competidores[i]);
                }
            }
        }
        estadoCarrera(competidores); // Mostrar el estado de la carrera
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } while (continua);

    std::cout << "\nCarrera finalizada. Podio:\n";
    for (const auto& conejo : podio) {
        std::cout << "Conejo " << conejo.forma << " completó " << conejo.vueltas << " vueltas.\n";
    }
}

void lanzar_iniciar_carrera() {
    std::thread carrera_thread(iniciar_carrera);
    carrera_thread.join();
}

void aumentar_competidores(int cants) {
    if (cants >= 0) {
        for (int i = 0; i < cants; i++) {
            conejo aux;
            aux.forma = rand() % 79 + 47;
            aux.posicion = 0;
            aux.vueltas = 0;
            aux.completo = false;
            competidores.push_back(aux);
        }
    }
}

void reducir_competidores(int cants) {
    if (cants >= 0) {
        for (int i = 0; i < cants; i++)
            competidores.pop_back();
    }
}

#endif
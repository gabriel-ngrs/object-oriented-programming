#include "sensor_temperatura.h"
#include "dispositivo_industrial.h" 
#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h> // sleep()

using namespace std;

bool sensor_temperatura::alerta_temperatura() {
    string mensagem;

    if (temp_atual > t_min && temp_atual < t_max) {
        mensagem = "Temperatura normal";
        cout << temp_atual << "C - " << mensagem << endl;
        informacao += to_string(temp_atual) + "C " + mensagem + "\n";
        return false;
    }
    else if (temp_atual > t_max) { 
        mensagem = "Temperatura alta";
        cout << temp_atual << " " << mensagem << endl;
        informacao += to_string(temp_atual) + "C " + mensagem + "\n";
        return true;
    }
    else {
        mensagem = "Temperatura baixa";
        cout << temp_atual << " " << mensagem << endl;
        informacao += to_string(temp_atual) + "C " + mensagem + "\n";
        return true;
    }
}



void sensor_temperatura::iniciar() {
    setStatus(true);
    while (getStatus()) {
        cout << "ID: " << getId() << endl;
        cout << "sensor_temperatura.h::iniciar()" << endl;
        cout << "cout: temp_atual = getTemperatura()" << getTemperatura();
        temp_atual = getTemperatura();
        cout << endl << "Sensor de temperatura em execução. Status: ativo." << endl;
        alerta_temperatura();
        cout << "Loop sleep 1s..." << endl;
        sleep(1); 
    }
}

void sensor_temperatura::parar() {
    cout << "sensor_temperatura::parar()" << endl;
    setStatus(false);
    gerar_relatorio();
}

string sensor_temperatura::gerar_relatorio() {
    informacao += "ID: " + getId() + "\n";
    informacao += "\n________ Limites de Temperatura ________\n";
    informacao += "Temperatura máxima permitida: " + to_string(t_max) + "C|\n";
    informacao += "Temperatura mínima permitida: " + to_string(t_min) + "C|\n";
    informacao += "________________________________________|\n";
    cout << endl << "Gerar relatorio(): " << endl;
    cout << informacao;
    return informacao;
}


#include "controlador_motor.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <unistd.h> // sleep()

using namespace std;

void controlador_motor::ajustar_velocidade(int nova_rpm) {
    if (nova_rpm > 0) {
        rpm = nova_rpm;
        aviso = "Maquina comeca a trabalhar com nova rpm: " + to_string(nova_rpm) + "\n";
        informacao += nova_rpm;
    }
    else {
        aviso = "rpm precisa ser maior que 0 \n";
        informacao += aviso;
        cout << aviso << endl;
    }
}
double controlador_motor::calcular_eficiencia() {
    aviso = "Calculando eficiencia da maquina \n";
    
    // Exemplo: eficiência = (potência / (rpm * constante))
    double constante = 1000; 
    
    // eficiência como uma função do RPM e da potência
    double eficiencia = (potencia / (rpm * constante)) * 100;
    aviso += "Eficiencia da maquina: " + to_string(eficiencia) + "\n";
    informacao += aviso;

    return eficiencia;
}
bool controlador_motor::verificar_seguranca() {
    if (potencia > 10000 || rpm > 8000) {
        aviso = "controlador_motor::verificar_seguranca(): Comportamento anômalo, taxas fora do normal, desligando máquina \n\n";
        cout << aviso << endl;
        informacao += aviso;
        return false;
    }
    else {
        aviso = "controlador_motor::verificar_seguranca(): Funciona normalmente \n\n";
        cout << aviso << endl;
        informacao += aviso;
        return true;
    }
}

void controlador_motor::iniciar() {

    setStatus(true);
    while (getStatus()) {
        cout << getId() << endl;
        cout << "controlador_motor::getStatus(): " << getStatus() << endl;
        cout << "RPM:" << rpm << endl;
        if (!verificar_seguranca()) {
            parar();
            break;
        }
        cout << endl << "Motor em execução. Status: ativo.\n" << endl;
        calcular_eficiencia();
        horas_de_uso += 1;
        cout << "Loop 1s... controlador_motor::iniciar()" << endl;
        cout << "---------------------------------------" << endl;
        sleep(1);
    }
}
void controlador_motor::parar() {
    aviso = "controlador_motor::parar() \n";
    setStatus(false);
    aviso += "Maquina parada com sucesso \n";
    cout << aviso << endl;
    informacao += aviso;
    gerar_relatorio();
}
string controlador_motor::gerar_relatorio() {
    cout << endl << "Relatório gerado: " << endl;
    informacao += "ID: " + getId() + "\n";
    informacao += "Tempo utilizacao: " + to_string(horas_de_uso) + "\n";
    cout << informacao; 
    
    return informacao;
}


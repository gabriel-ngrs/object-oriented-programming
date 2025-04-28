#include "dispositivo_industrial.h" 
#include "robo_manipulador.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;
using std::cout;
using std::to_string;
using std::endl;

// Métodos específicos
void robo_manipulador::mover_para(double x, double y, double z) {
    posicao_x = x;
    posicao_y = y;
    posicao_z = z;
    aviso += "Robo movido para a posicao" + to_string(posicao_x) + "," + to_string(posicao_y) + "," + to_string(posicao_z) + "\n";
    cout << aviso << endl;
    informacao += aviso;
}
void robo_manipulador::agarrar_objeto(double peso) {
    if (peso > carga_maxima) {
        aviso = "Peso excede a capacidade maxima do robo \n";
        informacao += aviso; 
        cout << aviso;
        throw invalid_argument(aviso);
    }
    carga_atual = peso;
    aviso = "Objeto de " + to_string(peso) + "kg agarrado. Carga atual: " + to_string(carga_atual) + "kg\n";
    cout << aviso << endl;
    informacao += aviso; 
}

void robo_manipulador::soltar_objeto() {
    aviso = "Soltando objeto de " + to_string(carga_atual) + "kgs... \n";
    carga_atual = 0;
    aviso += "Carga atual " + to_string(carga_atual);
    cout << aviso << endl;
    informacao += aviso;
}

// Implementações dos métodos virtuais puros
void robo_manipulador::iniciar() {
    setStatus(true);
    while (getStatus()) {
        cout << "ID: " << getId() << endl;
        verificar_seguranca();
        cout << "Robô manipulador iniciado. Posição inicial: (" 
        << posicao_x << ", " << posicao_y << ", " << posicao_z << ")" << endl;
        cout << "LOG: dentro do while loop esperando 1s robo_manipulador::iniciar()" << endl;
        sleep(1);
    }
}
void robo_manipulador::parar() {
    setStatus(false);
    cout << "Robô manipulador parado na posição atual: (" 
         << posicao_x << ", " << posicao_y << ", " << posicao_z << ")" << endl;
}

string robo_manipulador::gerar_relatorio() {
    string informacao;
    informacao += "\nRelatório robo\n";
    informacao += "ID: " + getId() + "\n";
    informacao += "Posição atual: (" + to_string(posicao_x) + ", " 
                 + to_string(posicao_y) + ", " + to_string(posicao_z) + ")\n";
    informacao += "Carga atual: " + to_string(carga_atual) + "kg\n";
    informacao += "Carga máxima: " + to_string(carga_maxima) + "kg\n";
    cout << informacao;
    return informacao;
}

// Sobrescrita do método verificar_seguranca
bool robo_manipulador::verificar_seguranca() {
    if (carga_atual > carga_maxima) {
        aviso = "ALERTA: Carga atual excede a capacidade maxima! \n";
        cout << aviso << endl;
        informacao += aviso; 
        parar();
        return false;
    }
    else {    
        aviso = "Robo operando dentro das condicoes de seguranca \n";
        informacao += aviso;
        cout << aviso << endl;
        return true;
    }

}
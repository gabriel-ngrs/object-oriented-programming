/*Exercício 1: Cálculo de Área de um Círculo
Objetivo: Implementar um programa que leia o raio de um círculo e exiba a área com 2 e 6 casas decimais.
Fórmula: ( A = \pi \cdot r^2 )
Requisitos:
1. Usar cin para entrada de dados.
2. Exibir a área com 2 e 6 casas decimais utilizando fixed e setprecision.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const float PI = 3.14;

float calcula_area(float raio) {
    float area;
    area = PI * (raio*raio);
    return area;
}

int main() {
    float area, raio;

    cout << "Informe o raio do circulo para calculo da area: " << endl;
    cin >> raio;

    area = calcula_area(raio);
    cout << "float 2 decimais: " << raio << " e " << fixed << setprecision(2) << area << endl;
    cout << "float 6 decimais: " << raio << " e " << fixed << setprecision(6) << area << endl;
    return 0;
}

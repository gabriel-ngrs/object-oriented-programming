/*Objetivo: Implementar um programa que leia 3 inteiros e exiba-os de forma alinhada à direita, ocupando 5
posições para cada número.
Requisitos:
1. Usar cin para entrada de dados.
2. Usar setw(5) para formatar cada número.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int n1, n2, n3;

    cout << "Digite o primeiro numero: ";
    cin >> n1;
    cout << "Digite o segundo numero: ";
    cin >> n2;
    cout << "Digite o terceiro numero: ";
    cin >> n3;
    
    cout << setw(5) << n1 << endl;
    cout << setw(5) << n2 << endl;
    cout << setw(5) << n3 << endl;
    return 0;
}

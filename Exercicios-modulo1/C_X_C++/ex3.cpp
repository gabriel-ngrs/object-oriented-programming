/*Objetivo: Criar um programa que leia nome, idade e altura de uma pessoa e exiba os dados formatados.
Requisitos:
1. Usar cin para entrada de dados.
2. Usar cout para exibir as informações de forma clara.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int idade;
    float altura;
    string nome;
    
    cout << "Digite seu nome" << endl;
    getline(cin, nome);
    cout << "Digite sua altura em centimetros" << endl;
    cin >> altura;
    cout << "Digite sua idade" << endl;
    cin >> idade;

    cout << nome << " tem " << altura << " de altura e tem " << idade << " anos." << endl;

    return 0;    

}
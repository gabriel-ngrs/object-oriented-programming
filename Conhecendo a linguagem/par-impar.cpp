#include <iostream>

int main() {
    int numero;
    std::cout << "Digite um numero inteiro: ";
    std::cin >> numero;
    if(numero%2 == 0) {
        std::cout << "O numero " << numero << " e par.";
    } else {
        std::cout << "O numero " << numero << " e impar"; 
    }
    return 0;
}


#include <iostream>

int main() {
    int n1, n2, temp;
    std::cout << "Digite o primeiro numero: " << std::endl;
    std::cin >> n1;
    std::cout << "Digite o segundo numero: " << std::endl;
    std::cin >> n2;

    temp = n1;
    n1 = n2;
    n2 = temp;
    std::cout << "Trocando valores" << std::endl;
    std::cout << "A variavel 1 agora e " << n1 << " E a variavel 2 agora e " << n2 << std::endl;

}
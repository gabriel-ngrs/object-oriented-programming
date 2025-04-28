#include <iostream>
using namespace std;

class Carro {
    private: 
        string marca;
        int ano;
    public:
        Carro(string marca_, int ano_){
            marca = marca_;
            ano = ano_;
        }

        ~Carro(){
            cout << "Destruindo o carro da marca: " << marca << endl;
        }

        void exibir(){
            cout << "Carro da marca: " << marca << " Ano: " << ano << endl;
        }
};

int main() {
    Carro c1("Hilux", 2020);
    Carro c2("Fiat", 2025);
    c1.exibir();
    c2.exibir();
    return 0;
}
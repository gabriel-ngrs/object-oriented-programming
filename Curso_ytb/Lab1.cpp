#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Conta {
    private:
        string nome;
        int conta;
        float saldo;
    public:

        Conta(string nome, int id, float saldo);
        void exibir() const;
        void depositar(float valor_deposito);
        void sacar(float valor_saque);

};
   


int main() {

    return 0;
}
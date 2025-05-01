/*Classe Completa com Construtor, Destrutor, Encapsulamento e Métodos Get
e Set
Objetivo: Criar a classe ContaBancaria, implementando construtores, destrutores, métodos get e set, e
funções para depósito e saque.
1. Atributos privados:
titular (string)
saldo (double)
2. Implemente os seguintes métodos públicos:
Construtor parametrizado: inicializa o nome do titular e o saldo inicial. Se o saldo for negativo,
ele é definido como zero.
Destrutor: exibe a mensagem: "Conta de X encerrada" (onde X é o nome do titular).
getSaldo: retorna o saldo.
setTitular: define o nome do titular.
depositar: soma o valor passado ao saldo. Valores negativos não devem ser aceitos.
sacar: subtrai o valor do saldo, mas apenas se houver saldo suficiente. Caso contrário, exiba a
mensagem "Saldo insuficiente!".
3. No main, crie uma conta para "Ana" com saldo de 1000. Realize as seguintes operações:
Deposite 200.
Saque 500.
Tente sacar 1000 (deve exibir "Saldo insuficiente!").
4. Exiba o saldo final.
Exemplo de saída esperada:
Saldo atual: 1000.00
Depósito de 200.00
Saque de 500.00
Saldo insuficiente!
Saldo final: 700.00
Conta de Ana encerrada*/
#include <iostream>
using namespace std;

class ContaBancaria {
    private:
        string titular;
        double saldo;
    public:
        ContaBancaria(string name, double valor){
            titular = name;
            if (valor < 0) {
                saldo = 0;
            } else {
                saldo = valor;
            }
            cout << "Conta no nome de " << titular << " iniciada com o saldo de R$ " << saldo << endl;
        }
        ~ContaBancaria(){
            cout << "Conta de " << titular << " encerrada" << endl;
        }
        
        double getSaldo(){return saldo;}
        void setTitular(string name) {titular = name;}

        void depositar(double valor){
            if (valor < 0 ){
                cout << "Nao e possivel depositar valores negativos!" << endl;
            } else {
                saldo += valor;
                cout << "Deposito no valor de R$ " << valor << " Feito com exito \nSeu saldo atualizado e R$ " << saldo << endl;
            }
        }
        void sacar(double quantia) {
            if(quantia < 0 || quantia > saldo) {
                cout << "Nao e possivel sacar esse valor!" << endl;
            } else {
                saldo -= quantia;
                cout << "Saque no valor de R$ " << quantia << " Feito com exito \nSeu saldo atualizado e R$ " << saldo << endl;
            }
        }
};



int main() {
    ContaBancaria cliente1("Ana", 1000);
    cliente1.depositar(200);
    cliente1.sacar(500);
    cliente1.sacar(1000);
    cliente1.getSaldo();
    return 0;
}
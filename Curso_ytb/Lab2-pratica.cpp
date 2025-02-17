/*Implemente	os	métodos	de	uma	classe para	representar	uma	conta	bancária.	Os	
dados	membro	da	classe	devem	incluir	o	nome	do	cliente	(uma	string),	o	número	
da	conta	(um	inteiro)	e	o	saldo	(um	ponto-flutuante).	
As	funções	membro	devem	permitir:
a. Criar	e	inicializar	um	objeto
b. Exibir	os	dados	da	conta
c. Depositar	dinheiro
d. Sacar	dinheiro*/

#include <iostream>
#include <string>
using namespace std;

int proximo_id = 1;

class Conta {
    private:
        string nome;
        int id;
        float saldo;
    public:
        Conta(string cliente, float valor){
            nome = cliente;
            id = proximo_id++;
            saldo = valor;
        }
        void exibir(){
            cout << "Nome: " << nome << endl;
            cout << "Id: " << id << endl;
            cout << "Saldo: " << saldo << endl;
        }
        void depositar(float valor) {
            saldo += valor;
            cout << "Deposito feito." << endl;
        }
        void sacar(float valor){
            if (valor > saldo) {
                cout << "Saldo insuficiente." << endl;
            } else {
                saldo -= valor;
                cout << "Saque feito." << endl;
            }
        }
};

int main() {
    Conta gabriel("Gabriel Negreiros Saraiva", 100);
    Conta joao("joao", 200);
    gabriel.exibir();
    joao.exibir();
    return 0;
}
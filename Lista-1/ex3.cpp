/*Encapsulamento e Validação em Setters
Objetivo: Criar uma classe Pessoa que respeite o princípio de encapsulamento.
1. Atributos privados:
nome (string)
idade (inteiro)
2. Implemente os métodos get e set para os atributos.
O setIdade deve validar que a idade é sempre positiva.
3. No main, crie um objeto da classe Pessoa, defina o nome e a idade usando os métodos set, e exiba as
informações da pessoa.
Regras de validação:
Caso o valor de idade seja negativo, exiba a mensagem: "Idade inválida!".*/


#include <iostream>
using namespace std;

class Pessoa{
    private:
        string nome;
        int idade;
    public:
        Pessoa(){
            nome = "";
        }
        ~Pessoa(){
        }
        void setNome(string name){
            nome = name;
        }
        void setIdade(int yearOld){
            if(yearOld <= 0){
                cout << "Idade invalida" << endl;
            } else {
                idade = yearOld;
            }
        }
        void getNome(){
            cout << nome << endl;
        }
        void getidade() {
            cout << idade << endl;
        }
};

int main(){
    Pessoa carlos;
    carlos.setNome("Carlos augusto melo de souza");
    carlos.setIdade(-10);
    carlos.setIdade(29);
    carlos.getidade();
    carlos.getNome();
    
    return 0;
}
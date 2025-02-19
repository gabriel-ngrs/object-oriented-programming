/*1) Você foi contratado para desenvolver um sistema para um hotel. O hotel possui uma
variedade de quartos que podem ser reservados pelos hóspedes. Cada quarto possui informações
como número, tipo (standard, luxo, suíte), capacidade e preço da diária. O hotel deseja acompanhar
o histórico de reservas de cada quarto e os hóspedes que já os reservaram. Cada hóspede que faz
uma reserva deve fornecer seu nome, CPF e telefone. O sistema deve permitir:
● Realizar uma nova reserva, onde um hóspede escolhe um quarto disponível e informa
quantos dias deseja reservar.
● O valor total da reserva é calculado com base no preço da diária e na quantidade de dias.
● Exibir um histórico dos hóspedes que reservaram cada quarto, incluindo as datas das
reservas.
Considere que um hóspede chamado João Silva, CPF 987.654.321-00, deseja reservar um quarto
específico do hotel, uma suíte com capacidade para 4 pessoas, número 101, e preço da diária de R$
300,00. João pretende reservar este quarto por 3 dias. Com base na história e no cenário, responda
às seguintes perguntas:
a. Identifique as classes principais que você criaria para representar esse sistema.
b. Descreva como seriam criados os objetos manipulados nesse cenário.
c. Liste atributos e métodos que cada classe teria, e explique o encapsulamento deles.
d. Explique os tipos de associações que ocorrem entre as classes.
e. Esboce as classes em C++ com os atributos e métodos mencionados.*/
#include <iostream>
#include <string>
using namespace std;

class Hospede {
    private:
        string cpf;
        string nome;
        string telefone;
    public:
        Hospede(string cpff, string name, string numero){
            cpf = cpff;
            nome = name;
            telefone = numero;
        }
        void exibir(){
            cout << "Hóspede: " << nome << ", CPF: " << cpf << ", Telefone: " << telefone << endl;
        }
};

class Reserva {
    Hospede hospede;
    int dias;
    float valortotal;
};

class Quarto {
    private:
        int numero;
        int tipo; // 1-standard, 2-luxo, 3-suíte
        int capacidade;
        float preco_diaria;
        
    public:
        Quarto(int nmr, int tip, int capac, float preco){ // Construtor
            numero = nmr;
            tipo = tip;
            capacidade = capac;
            preco_diaria = preco;
            ocupado = 0; // Quarto livre
        }
        void reservar()

};




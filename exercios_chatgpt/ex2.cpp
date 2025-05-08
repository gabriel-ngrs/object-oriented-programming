/*🧪 Exercício 2 – Sistema de Locadora de Filmes
🎯 Enunciado:
Crie um sistema básico para uma locadora de filmes, que permita cadastrar clientes, filmes e registrar os empréstimos.

🔍 Requisitos:
A classe base Pessoa contém nome, CPF e telefone.

Cliente herda de Pessoa e pode alugar filmes.

Filme contém título, gênero, duração e se está disponível ou não.

Emprestimo contém:

o filme alugado

o cliente

a data do empréstimo*/

#include <iostream>
#include <vector>
using namespace std;

class Emprestimo;  // Declarar antes para nao dar pau depois
class Pessoa;

class Pessoa {  // Classe Base 
    private:
        string nome;
        string cpf;
        string telefone;
    public:
        Pessoa(string NOME, string CPF, string TELEFONE) { // Construtor 
            nome = NOME;
            cpf = CPF;
            telefone = TELEFONE;
            cout << "Pessoa cadastrada com sucesso!" << endl;
        }
        ~Pessoa(){}

        // Getters + Setters
        string get_Nome(){return nome;}
        string get_Cpf(){return cpf;}
        string get_Telefone(){return telefone;}
        void set_Nome(string NOME){nome = NOME;}
        void set_Cpf(string CPF){cpf = CPF;}
        void set_Telefone(string TELEFONE){telefone = TELEFONE;}
};
 
class Filme {
    private:
        string titulo;
        string genero;
        float duracao;
        bool disponivel;
    public:
        Filme(string TITULO, string GENERO, float DURACAO) {
            titulo = TITULO;
            genero = GENERO;
            duracao = DURACAO;
            disponivel = true;
            cout << "Filme: " << titulo << " cadastrado com sucesso!" << endl;
        }
        ~Filme(){}

        string get_Titulo() {return titulo;}
        string get_Genero() {return genero;}
        float get_Duracao() {return duracao;}
        bool get_Disponivel() {return disponivel;}
        void set_Disponivel(bool DISPONIVEL){disponivel = DISPONIVEL;}
};

class Cliente : public Pessoa { // Herda da classe base
    private:
        vector<Emprestimo*> emprestimos; // Lista de vetor para listar os emprestimos por cliente
    public:
        // Herdando construtor
        Cliente(string nome, string cpf, string telefone) : Pessoa(nome, cpf, telefone){} 

        void adicionar_emprestimo(Emprestimo* emprestimo) {
            emprestimos.push_back(emprestimo);
        }
};      

class Emprestimo {
    private:
        // Passando por ponteiro para que mude os valores na respectiva classe
        Cliente* cliente;  
        Filme* filme;
        string data_emprestimo;
    public:
        Emprestimo(Filme* f, Cliente* c, string data){
            if(f->get_Disponivel() == true) {
                filme = f;
                cliente = c;
                data_emprestimo = data;
                cliente->adicionar_emprestimo(this);
                filme->set_Disponivel(false);
                cout << "Emprestimo feito!" << endl; 
            } else {
                cout << "Filme indisponivel no momento!" << endl;
            }
        }
        ~Emprestimo(){}

};
int main(){
    Cliente c1("Gabriel Negreiros Saraiva", "715.681.004-93", "(83) 9 9843-6065");
    Filme f1("Debi & Loide", "Comedia", 2015);

    Cliente c2("Iviny Leticia", "715.681.004-93", "(83) 9 9843-6065");
    Filme f2("Anabele", "Terror", 2000);

    Emprestimo e1(&f1, &c1, "08/05/2025");
    Emprestimo e2(&f1, &c2, "08/05/2025");

    return 0;
}
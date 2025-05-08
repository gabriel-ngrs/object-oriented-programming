#include <iostream>
#include <vector>
using namespace std;

// Forward declarations
class Emprestimo;
class Filme;
class Pessoa;

// Declaração da classe Cliente (sem implementação dos métodos que usam Emprestimo)
class Cliente : public Pessoa {
private:
    vector<Emprestimo*> emprestimos;
public:
    Cliente(string nome, string cpf, string telefone);
    void adicionar_emprestimo(Emprestimo* emprestimo);
    void exibir_emprestimos();
};

// Definição completa de Filme
class Filme {
private:
    string titulo;
    string genero;
    float duracao;
    bool disponivel;
public:
    Filme(string TITULO, string GENERO, float DURACAO);
    string get_Titulo();
    string get_Genero();
    float get_Duracao();
    bool get_Disponivel();
    void set_Disponivel(bool DISPONIVEL);
};

// Definição completa de Pessoa
class Pessoa {
private:
    string nome;
    string cpf;
    string telefone;
public:
    Pessoa(string NOME, string CPF, string TELEFONE);
    string get_Nome();
    string get_Cpf();
    string get_Telefone();
    void set_Nome(string NOME);
    void set_Cpf(string CPF);
    void set_Telefone(string TELEFONE);
};

// Definição completa de Emprestimo
class Emprestimo {
private:
    Filme* filme;
    Cliente* cliente;
    string data_emprestimo;
public:
    Emprestimo(Filme* f, Cliente* c, string data);
    Filme* getFilme();
    string getData();
    Cliente* getCliente();
};

// Implementações dos métodos de Pessoa
Pessoa::Pessoa(string NOME, string CPF, string TELEFONE) : 
    nome(NOME), cpf(CPF), telefone(TELEFONE) {
    cout << "Pessoa cadastrada com sucesso!" << endl;
}

string Pessoa::get_Nome() { return nome; }
string Pessoa::get_Cpf() { return cpf; }
string Pessoa::get_Telefone() { return telefone; }
void Pessoa::set_Nome(string NOME) { nome = NOME; }
void Pessoa::set_Cpf(string CPF) { cpf = CPF; }
void Pessoa::set_Telefone(string TELEFONE) { telefone = TELEFONE; }

// Implementações dos métodos de Filme
Filme::Filme(string TITULO, string GENERO, float DURACAO) : 
    titulo(TITULO), genero(GENERO), duracao(DURACAO), disponivel(true) {
    cout << "Filme: " << titulo << " cadastrado com sucesso!" << endl;
}

string Filme::get_Titulo() { return titulo; }
string Filme::get_Genero() { return genero; }
float Filme::get_Duracao() { return duracao; }
bool Filme::get_Disponivel() { return disponivel; }
void Filme::set_Disponivel(bool DISPONIVEL) { disponivel = DISPONIVEL; }

// Implementações dos métodos de Cliente
Cliente::Cliente(string nome, string cpf, string telefone) : 
    Pessoa(nome, cpf, telefone) {}

void Cliente::adicionar_emprestimo(Emprestimo* emprestimo) {
    emprestimos.push_back(emprestimo);
}

void Cliente::exibir_emprestimos() {
    cout << "Emprestimos do cliente " << get_Nome() << ":" << endl;
    if (emprestimos.empty()) {
        cout << "Nenhum emprestimo registrado." << endl;
        return;
    }
    for (Emprestimo* emp : emprestimos) {
        cout << "Filme: " << emp->getFilme()->get_Titulo()
             << ", Data: " << emp->getData() << endl;
    }
}

// Implementações dos métodos de Emprestimo
Emprestimo::Emprestimo(Filme* f, Cliente* c, string data) {
    if (f->get_Disponivel()) {
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

Filme* Emprestimo::getFilme() { return filme; }
string Emprestimo::getData() { return data_emprestimo; }
Cliente* Emprestimo::getCliente() { return cliente; }

// Função main
int main() {
    Cliente c1("Gabriel Negreiros Saraiva", "715.681.004-93", "(83) 9 9843-6065");
    Filme f1("Debi & Loide", "Comedia", 2015);

    Cliente c2("Iviny Leticia", "715.681.004-93", "(83) 9 9843-6065");
    Filme f2("Anabele", "Terror", 2000);

    Emprestimo e1(&f1, &c1, "08/05/2025");
    Emprestimo e2(&f1, &c2, "08/05/2025");

    c1.exibir_emprestimos();

    return 0;
}
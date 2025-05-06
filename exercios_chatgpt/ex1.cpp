/*Exercício 1 – Clínica Veterinária
🎯 Enunciado:
Você foi contratado para desenvolver um sistema simples de cadastro de consultas em uma clínica veterinária. O sistema deve permitir:

Cadastrar os clientes (donos dos animais).

Cadastrar os animais de cada cliente.

Registrar consultas feitas pelos animais.

🔍 Requisitos:
Cada Pessoa tem nome, CPF e telefone.

Cada Cliente é uma Pessoa.

Cada Animal tem nome, espécie (ex: cão, gato) e idade. Um cliente pode ter vários animais.

Cada Consulta deve conter a data, o nome do veterinário, o animal atendido e a descrição do diagnóstico.*/

#include <iostream>
#include <vector>
using namespace std;

class Pessoa {
    private:
        string nome;
        string cpf;
        string telefone;
    public:
        Pessoa(string name, string CPF, string TELEFONE){  // Construtor
            nome = name;
            cpf = CPF;
            telefone = TELEFONE;
            cout << "Pessoa Cadastrada com exito." << endl;
        }
        ~Pessoa(){} // Destrutor

        string get_Nome() const { return nome; }
        string get_Cpf() const { return cpf; }
        string get_Telefone() const { return telefone; }
        void set_Nome(string name) { nome = name; }
        void set_Cpf(string CPF) { cpf = CPF; }
        void set_Telefone(string TELEFONE) { telefone = TELEFONE; }
};

class Animal {
    private:
        string nome;
        string especie;
        int idade;
    public:
        Animal(string NOME, string ESPECIE, int IDADE){  // Construtor 
            nome = NOME;
            especie = ESPECIE;
            idade = IDADE;
        }
        ~Animal(){} // Destrutor

        string get_Nome() const { return nome;}
};

class Cliente : public Pessoa  { // Cliente herdando os metodos publicos da classe base Pessoa
    private:
        vector<Animal> animais;  // Utilizando o vector para criar uma lista de Animais para o cliente
    public:
        Cliente(string nome, string cpf, string telefone) : Pessoa(nome, cpf, telefone) {}  // Herdando o construtor da classe base Pessoa

        void adicionar_animal(const Animal& animal){
            animais.push_back(animal);  // Funçao da biblioteca vector para adicionar o elemento na lista
        }

        void listar_animais(){
            cout << "Lista de animais: " << endl;

            for(int i=0; i < animais.size(); i++) {
                cout <<"Animal " << i+1 << " " << animais[i].get_Nome() << endl;  // Utilizando o get_Nome pois so o cout n vai, precisa sobrecarregar os operadores
            }
        }
};

class Veterinario : public Pessoa {
    public:
        Veterinario(string nome, string cpf, string telefone) : Pessoa(nome, cpf, telefone) {} // Herdando o construtor da classe base Pessoa
};

class Consulta {
    private:
        string data;
        Veterinario vet;
        Animal pet;
        string diagnostico;
    public:

        Consulta(const string& DATA, const Veterinario& vete, const Animal& pete, const string& diag)
            : data(DATA), vet(vete), pet(pete), diagnostico(diag) {} // Construtor com lista de inicializaçao, para evitar q o compilador chame o construtor padrao

        ~Consulta(){} // Destrutor

        void exibir_consulta(){
            cout << "Data: " << data << endl;
            cout << "Veterinario: " << vet.get_Nome() << endl;
            cout << "Animal: " << pet.get_Nome() << endl;
            cout << "Diagnostico: " << diagnostico << endl;
        }
};

int main(){
    cout << "Criando cliente" << endl;
    Cliente c1 ("Gabriel Negreiros Saraiva", "715.681.004-93", "(83) 9 9843-6065");

    cout << "Criando animal" << endl;
    Animal a1 ("Toy", "Cachorro", 5);
    Animal a2 ("Bob", "Cachorro", 2);
    Animal a3 ("Berto", "Papagaio", 1);

    cout << "Adicionando animais ao cliente: " << c1.get_Nome() << endl;
    c1.adicionar_animal(a1);
    c1.adicionar_animal(a2);
    c1.adicionar_animal(a3);
    cout << "Animais adicionados com exito" << endl;

    c1.listar_animais();

    cout << "Cadastrando Veterinario" << endl;
    Veterinario v1("Cleiton da Silva", "723.987.324-26", "(83) 9 9854-5452");

    cout << "Cadastrando Consultas" << endl;
    Consulta consulta1("05/05/2025", v1, a1, "Alergia leve a racao");
    Consulta consulta2("06/05/2025", v1, a3, "Diarreia grave");
    
    consulta1.exibir_consulta();
    cout << endl;
    consulta2.exibir_consulta();
    return 0;
}

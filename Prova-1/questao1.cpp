#include <iostream>
using namespace std;

class Visitante {
    private:
        string nome;
        string cpf;
        int idade;
        int altura_cm;
    public:
        Visitante(string NOME, string CPF, int IDADE, int ALTURA ) {
            nome = NOME;
            cpf = CPF;
            idade = IDADE;
            altura_cm = ALTURA;
            cout << "Cliente criado com sucesso." << endl;
        }
        ~Visitante(){}

        string get_nome(){return nome;}
        string get_cpf(){return cpf;}
        int get_idade(){return idade;}
        int get_altura(){return altura_cm;}
};

class Brinquedo {
    private:
        string nome;
        string categoria;
        int capacidade_max;
        int altura_cm;
        int tempo_min;
    public:
        Brinquedo(string NOME, string CATEGORIA, int CAPACIDADE, int ALTURA, int TEMPO_MINIMO){
            nome = NOME;
            categoria = CATEGORIA;
            capacidade_max = CAPACIDADE;
            altura_cm = ALTURA;
            tempo_min = TEMPO_MINIMO;
            cout << "Brinquedo criado com sucesso." << endl;
        }
        ~Brinquedo(){}

        string get_nome(){return nome;}
        string get_categoria(){return categoria;}
        int get_capacidade_max(){return capacidade_max;}
        int get_altura_cm(){return altura_cm;}
        int get_tempo_min(){return tempo_min;}
};

class Ingresso {
    private:
        Visitante* v;
        Brinquedo* b;

    public:
        Ingresso(Visitante* V, Brinquedo* B){
            v = V;
            b = B;
        }
        ~Ingresso(){}
};


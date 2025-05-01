/*Construtores com Parâmetros de Valor Padrão
Objetivo: Implementar a classe Aluno para trabalhar com construtores que possuem valores padrão para os
parâmetros.
1. Atributos privados:
nome (string)
nota (double)
2. O construtor parametrizado deve ter o nome com valor padrão "Aluno Desconhecido" e a nota com
valor padrão 0.0.
3. Implemente os métodos get e set para os atributos.
4. No main, crie três objetos de Aluno:
Um sem passar argumentos (usa os valores padrão).
Um passando apenas o nome.
Um passando o nome e a nota.
5. Exiba as informações dos três objetos.
Dicas:
Lembre-se de definir os valores padrão da direita para a esquerda*/

#include <iostream>
using namespace std;

class Aluno {
    private:

        string nome;
        double nota;
    public:

        Aluno(string name = "Aluno Desconhecido", double n = 0.00){
            nome = name;
            nota = n;
        }

        ~Aluno(){
        }

        void setNome(string name){nome = name;}
        void setNota(double n){nota = n;}
        void getNome(){cout << "Aluno: " << nome << endl;}
        void getNota(){cout << "Nota: " << nota << endl;}
};

int main(){
    Aluno a1;
    Aluno a2("Maria");
    Aluno a3("Gabriel", 10);

    a1.getNome();
    a1.getNota();
    a2.getNome();
    a2.getNota();
    a3.getNome();
    a3.getNota();
    
    return 0;
}
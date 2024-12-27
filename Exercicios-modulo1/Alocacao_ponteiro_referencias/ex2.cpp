/*Objetivo: Implementar um programa em C e C++ que utilize structs (em C) e classes (em C++) para
manipular informações de alunos. O aluno deverá aplicar conceitos de alocação dinâmica de memória,
ponteiros, arrays dinâmicos e referências para criar, manipular e liberar as estruturas de dados.
1. Parte 1 (C):
Implemente uma struct Aluno que contém:
ID (inteiro)
Nome (string com 50 caracteres)
Nota (float)
O programa deve:
Solicitar ao usuário a quantidade de alunos.
Alocar dinamicamente memória para armazenar esses alunos.
Permitir que o usuário insira os dados de cada aluno (ID, Nome e Nota).
Exibir a lista de alunos cadastrados.
Liberar a memória alocada.

2. Parte 2 (C++):
Converta o programa para C++ utilizando uma classe Aluno com os mesmos atributos (ID,
Nome, Nota).
Implemente métodos da classe para:
Definir os atributos (setID, setNome, setNota).
Exibir os dados (método exibirDados).
O programa deve:
Solicitar a quantidade de alunos.
Alocar dinamicamente o array de objetos Aluno.
Usar métodos de classe para definir os dados de cada aluno.
Exibir a lista de alunos.
Usar delete[] para liberar a memória.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    float nota;

} Aluno;

int main() {
    int n_alunos;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n_alunos);

    Aluno* alunos = (Aluno*)malloc(n_alunos*sizeof(Aluno)); //alocando memoria suficiente para a quantidade de structs que quero colocar

    for(int i=0;i<n_alunos;i++) {
        alunos[i].id = i+1;
        printf("Informe o nome do aluno %d: ", alunos[i].id);
        scanf("%s", alunos[i].nome);
        printf("\n");
        printf("Informe a nota do aluno %d: ", alunos[i].id);
        scanf("%f", &alunos[i].nota);

    }
    
    printf("Lista de alunos: \n");
    for(int i=0;i<n_alunos;i++) {
        printf()
    }
}

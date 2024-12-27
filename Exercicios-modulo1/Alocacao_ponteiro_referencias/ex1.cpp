/*Exercício 1
Objetivo: Implementar um programa que permita ao aluno praticar a alocação dinâmica de memória, o uso
de ponteiros, arrays e referências. O aluno deve ser capaz de manipular essas estruturas de forma integrada,
tanto em C quanto em C++.
1. Parte 1 (C):
Escreva um programa que:
Peça ao usuário para informar o tamanho de um array de inteiros.
Use malloc para alocar dinamicamente a memória para o array.
Preencha o array com os quadrados dos números de 0 a (tamanho-1).
Imprima os valores do array.
Libere a memória alocada com free.

Converta o programa de C para C++.
Use new e delete para substituir malloc e free.
Implemente uma função que receba uma referência a uma variável e a dobre.
Após imprimir os valores do array, use a função para dobrar o valor do último elemento do array.
Imprima o array novamente.*/

/*Codigo em C*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o tamanho do array ");
    scanf("%d", &n);

    int *arr = (int *)malloc(10* sizeof(int));
    if (arr == NULL) {
        printf("Erro de memoria!\n");
        return 1;
    }

    for (int i=0; i<n; i++) {
        arr[i] = i * i;
    }

    printf("Os quadrados são: ");
    for (int i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}

/*Fim do codigo em C*/

/*Codigo em C++*/
#include <iostream>
using namespace std;

void dobra(int &ref) {
    ref = ref * 2;
    cout << ref;
}

int main() {
    int n;
    cout << "Digite o tamanho do array: ";
    cin >> n;

    int* arr = new int[n];
    if (!arr) {
        cout << "Erro de memoria!";
        return 1;
    }

    for (int i=0; i<n; i++) {
        arr[i] = i*i;
    }

    cout << "Resultado" << endl;
    for(int i =0;i<n;i++) {
        cout << arr[i];
        cout << " ";
    }

    cout << endl;
    int &ref = arr[n-1];
    dobra(ref);
    cout << endl;

    for(int i =0;i<n;i++) {
        cout << arr[i];
        cout << " ";
    }

    delete arr;
    return 0;

}
/*Fim do codigo em C++*/
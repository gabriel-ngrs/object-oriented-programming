/*Crie uma classe Fracao que representa uma fração com numerador e denominador.

Implemente:

Um construtor que recebe numerador e denominador

Uma função print() que exibe a fração no formato numerador/denominador

A sobrecarga do operador * para multiplicar duas frações.

*/
#include <iostream>
using namespace std;

class Fracao{
    private:
        float numerador;
        float denominador;
    public:
        Fracao(float n, float d) {
            numerador = n;
            denominador = d;
        }

        Fracao operator*(const Fracao& outra) {
            int novoNumerador = numerador * outra.numerador;
            int novoDenominador = denominador * outra.denominador;
            return Fracao(novoNumerador, novoDenominador);
        }

        void print() {
            cout << numerador << "/" << denominador << endl;
        }
};

int main(){
    Fracao f1(3, 5);
    Fracao f2(3, 2);

    Fracao resultado = f1 * f2;
    resultado.print();
    return 0;
}
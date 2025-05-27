/*Exercício 1: Funções sobrecarregadas
Crie uma classe chamada Conversor com três funções converte:

Uma que converte metros para centímetros (recebe double)

Outra que converte horas para minutos (recebe int)

Outra que converte char para código ASCII (recebe char)

Chame todas no main.*/

#include <iostream>
using namespace std;

class Conversor{
    public:
        Conversor(){}

        double converte(double metro) {
            return metro * 100;
        }

        int converte(int horas) {
            return horas * 60;
        }

        int converte(char c) {
            return c;
        } 
};

int main(){
    Conversor c;
    cout << c.converte(10.0) << endl;
    cout << c.converte(1) << endl;
    cout << c.converte('G');
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Jogo
{
private:
 string nome; // nome do jogo
 float preco; // preço do jogo
 int horas; // quantidade de horas jogadas
 float custo; // valor por hora jogada

 void calcular() { if (horas > 0) custo = preco/horas; }
public:

 void adquirir(const string& titulo, float valor){
    nome = titulo;
    preco = valor;
    horas = 0;
    custo = valor;
 }
 void atualizar(float valor){
    preco = valor;
    calcular();
 }
 void jogar(int tempo){
    horas += tempo;
    calcular();
 }
 void exibir(){
    cout << nome << "\n" << preco << "\n" << horas << "\n" << custo;
 }
};  

int main() {
    Jogo minecraft;
    Jogo cs2;
    minecraft.adquirir("minecraft", 150);
    cs2.adquirir("Counter Strike 2", 70);

    cout << &minecraft << endl;
    cout << &cs2 << endl;
    return 0;
}
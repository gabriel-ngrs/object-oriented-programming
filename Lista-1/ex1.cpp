#include <iostream>

using namespace std;

class Produto{
    private:
        string nome;
        double preco;
    
    public:
        Produto(string name, double price) {
            nome = name;
            preco = price;
        }

        void exibir(){
            cout << "Nome: " << nome << ", Preco: " << preco << endl;
        }        
};

int main() {
    Produto cuscuz("Cuscuz Novomilho", 5.90);
    Produto ovo("30 Ovos galinha caipira", 400);

    cuscuz.exibir();
    ovo.exibir();

    return 0;
}
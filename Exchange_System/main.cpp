#include <iostream>
#include <string.h>
using namespace std;

class Carteira {
private:
    char endereco[50]; 
    float saldo_btc;
    float saldo_eth;
    float saldo_brl;

public:
//METODOS ESPECIAIS
    //Construtor
    Carteira(const char* _endereco, float btc, float eth, float brl) {
        strncpy(endereco, _endereco, 50); // Copia o endereço da carteira
        saldo_btc = btc;
        saldo_eth = eth;
        saldo_brl = brl;
        cout << "Carteira " << endereco << " criada com sucesso!" << endl;
    }
    //Destrutor
    ~Carteira() {
        cout << "Carteira " << endereco << " foi removida da memoria." << endl;
    }
//METODOS 
    void alterar_saldo (float btc, float eth, float brl) {
        saldo_btc += btc;
        saldo_eth += eth;
        saldo_brl += brl;
    }
    void exibir_saldo() {
        cout << "Carteira (" << endereco << "):\n";
        cout << "BTC: " << saldo_btc << "\n";
        cout << "ETH: " << saldo_eth << "\n";
        cout << "BRL: " << saldo_brl << "\n";
        cout << "------------------------\n";
    }
//GETTERS/SETTERS
    float getSaldoBTC() const { return saldo_btc; }
    float getSaldoETH() const { return saldo_eth; }
    float getSaldoBRL() const { return saldo_brl; }

    void setSaldoBTC(float btc) { saldo_btc = btc;}
    void setSaldoETH(float eth) { saldo_eth = eth;}
    void setSaldoBRL(float brl) { saldo_brl = brl;}
};

class Transacao {
private: 
    char tipo_transacao[20];  // compra ou venda
    char tipo_moeda[10]; // btc, eth
    float quantidade;  // quantidade de criptos
    float preco_unitario;  // preço por unidade de cripto
    Carteira* origem;   // ponteiro para carteira de origem
    Carteira* destino;   // ponteiro para carteira de destino

public:

    float calcular_total() {
        return quantidade * preco_unitario;
    }

    void executar_transacao () {
        float total = calcular_total();
        if (tipo_transacao == "COMPRA") {
            if (origem->getSaldoBRL() >= total) {  // Verificando se tem dinheiro suficiente
                if (tipo_moeda == "BTC") {
                    origem->setSaldoBRL(origem->getSaldoBRL() - total); // retirando o dinheiro
                    destino->setSaldoBTC(destino->getSaldoBTC() + quantidade); // comprando as criptos
                    cout << "Transacao de COMPRA realizada com sucesso!" << endl;
                } else {
                    origem->setSaldoBRL(origem->getSaldoBRL() - total); // retirando o dinheiro
                    destino->setSaldoETH(destino->getSaldoETH() + quantidade); // comprando as criptos
                    cout << "Transacao de COMPRA realizada com sucesso!" << endl;
                }
            }
            else {
                 cout << "Saldo insuficiente para realizar a COMPRA!" << endl;
            }
        } 

        else if (tipo_transacao == "VENDA") {
            if (tipo_moeda == "BTC") {
                if (origem->getSaldoBTC() >= quantidade) { // Verificando se tem cripto suficiente
                    origem->setSaldoBTC(origem->getSaldoBTC() - quantidade);
                    destino->setSaldoBRL(destino->getSaldoBRL() - total);
                    cout << "Transacao de VENDA realizada com sucesso!" << endl;
                } else {
                    cout << "Saldo insuficiente para realizar a VENDA!" << endl;
                }
            } else {
                if (origem->getSaldoETH() >= quantidade) { // Verificando se tem cripto suficiente
                    origem->setSaldoETH(origem->getSaldoETH() - quantidade);
                    destino->setSaldoBRL(destino->getSaldoBRL() - total);
                    cout << "Transacao de VENDA realizada com sucesso!" << endl;
                } else {
                    cout << "Saldo insuficiente para realizar a VENDA!" << endl;
                }
            } 
        } 
        else {
            cout << "Tipo de transacao invalida!" << endl;
        }
    }
};
int main () {
    return 0;
}

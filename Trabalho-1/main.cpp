#include <iostream>
using namespace std;

const float preco_btc = 582.000;
const float preco_eth = 15.000;

class Carteira {
    private:
        string endereco;
        float saldo_btc;
        float saldo_eth;
        float saldo_brl;
    public:
        Carteira(string ENDERECO){
            endereco = ENDERECO;
            saldo_btc = 0;
            saldo_eth = 0;
            saldo_brl = 0;
            cout << "Carteira criada!\n"; 
        }
        ~Carteira(){}

        float get_saldoBtc(){return saldo_btc;}
        float get_saldoEth(){return saldo_eth;}
        float get_saldobrl(){return saldo_brl;}

        void set_saldoBtc(float valor){saldo_btc += valor;}
        void set_saldoEth(float valor){saldo_eth += valor;}
        void set_saldoBrl(float valor){saldo_brl += valor;}
};

class Transacao {
    private:
        string tipo;
        string moeda;
        float quantidade;
        Carteira* origem;
        Carteira* destino;
    public:
        Transacao(string TIPO, string MOEDA, float QUANTIDADE, Carteira* ORIGEM, Carteira* DESTINO){
            tipo = TIPO;
            moeda = MOEDA;
            quantidade = QUANTIDADE;
            origem = ORIGEM;
            destino = DESTINO;
        }
        ~Transacao(){}
        
        float calcular_total(){
            if (moeda == "BTC") {
                return quantidade * preco_btc;
            } else {
                return quantidade * preco_eth;
            }
        }

        void executar_transacao(){
            if (tipo == "COMPRA") {  // Caso compra  
                if(origem->get_saldobrl() >= calcular_total()) {  // Verificado se tem dinheiro suficiente
                    if (moeda == "BTC") {  // Para btc
                        origem->set_saldoBtc(quantidade);  // Adicionando o saldo a carteira
                        origem->set_saldoBrl(calcular_total() *-1);  // Retirando da carteira o valor em dinheiro, -1 serve para tornar o valor negativo
                        cout << "Compra de " << quantidade << " " << moeda << " realizada com sucesso!" << endl;    
                    } else {  // Para eth
                        origem->set_saldoEth(quantidade);  // Adicionando o saldo a carteira
                        origem->set_saldoBrl(calcular_total() *-1);  // Retirando da carteira o valor em dinheiro, -1 serve para tornar o valor negativo
                        cout << "Compra de " << quantidade << " " << moeda << " realizada com sucesso!" << endl; 
                    }
                } else {
                    cout << "Voce nao tem saldo suficiente para efeturar a compra!\n";
                }
            } else { // Caso venda
                if (moeda == "BTC") {
                    if (origem->get_saldoBtc()>= quantidade) {
                        origem->set_saldoBtc(quantidade *-1);  // Removendo o saldo em btc
                        origem->set_saldoBrl(calcular_total());  // Adicioanando saldo em brl
                        cout << "Venda de " << quantidade << " " << moeda << " realizada com sucesso!" << endl;
                    } else {
                        cout << "Saldo insuficiente para venda!" << endl;
                    }
                } else {
                    if (origem->get_saldoEth()>= quantidade) {
                        origem->set_saldoEth(quantidade *-1);  // Removendo o saldo em btc
                        origem->set_saldoBrl(calcular_total());  // Adicioanando saldo em brl
                        cout << "Venda de " << quantidade << " " << moeda << " realizada com sucesso!" << endl;
                    } else {
                        cout << "Saldo insuficiente para venda!" << endl;
                    }
                    
                }
            }
        }
};

class Exchange {
    private:
        Carteira* carteiras;
        Transacao* transacoes;
        int num_carteiras;
        int num_transacoes;
    public:

};  

int main(){
    return 0;
}
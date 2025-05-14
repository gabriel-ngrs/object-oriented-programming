#include <iostream>
#include <vector>
using namespace std;

const double preco_btc = 582.000;
const double preco_eth = 15.000;

class Carteira {
    private:
        string endereco;
        double saldo_btc;
        double saldo_eth;
        double saldo_brl;
    public:
        Carteira(string ENDERECO){
            endereco = ENDERECO;
            saldo_btc = 0;
            saldo_eth = 0;
            saldo_brl = 0;
            cout << "Carteira criada!\n"; 
        }
        ~Carteira(){}

        double get_saldoBtc(){return saldo_btc;}
        double get_saldoEth(){return saldo_eth;}
        double get_saldobrl(){return saldo_brl;}
        string get_endereco(){return endereco;}

        void set_saldoBtc(double valor){saldo_btc += valor;}
        void set_saldoEth(double valor){saldo_eth += valor;}
        void set_saldoBrl(double valor){saldo_brl += valor;}
};

class Transacao {
    private:
        string tipo;
        string moeda;
        double quantidade;
        Carteira* origem;
    public:
        Transacao(string TIPO, string MOEDA, double QUANTIDADE, Carteira* ORIGEM){
            tipo = TIPO;
            moeda = MOEDA;
            quantidade = QUANTIDADE;
            origem = ORIGEM;
        }
        ~Transacao(){}
        
        double calcular_total(){
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
        vector<Carteira*> carteiras;  // Vetor para armazenar as carteiras
        vector<Transacao*> transacoes;  // Vetor para armazenar as transacoes
        int num_carteiras;
        int num_transacoes;
    public:
        Exchange(){
            num_carteiras=0;
            num_transacoes=0;
        }
        ~Exchange(){
            for (Carteira* c : carteiras) delete c;
            for (Transacao* t : transacoes) delete t;
        }

        void adicionar_carteira(string endereco){
            Carteira* nova_carteira = new Carteira(endereco);  // Criando a carteira
            carteiras.push_back(nova_carteira);  // Adicionando ela ao vetor
            num_carteiras++;  // Atualizando o contador
        }

        void realizar_transacao(string tipo, string moeda, double quantidade, Carteira* origem) {
            Transacao* nova_transacao = new Transacao(tipo, moeda, quantidade, origem);
            nova_transacao->executar_transacao();
            transacoes.push_back(nova_transacao);
            num_transacoes++;
        }

        void depositar_brl(string endereco, double quantia){
            for (Carteira* c : carteiras) {
                if (c->get_endereco() ==  endereco) {
                    c->set_saldoBrl(quantia);
                    cout << "Deposito feito com sucesso!" << endl;
                    return;
                }
            }
            cout << "Carteira com endereco " << endereco << " nao encontrada!" << endl;
        }

        void exibir_carteiras(){
            if(carteiras.empty()) {  // Verificando se o vetor está vazio
                cout << "Nenhuma carteira cadastrada" << endl; 
                return;
            }

            cout << "---CARTEIRAS CADASTRADAS---" << endl;
            for(int i=0; i < carteiras.size(); i++) {
                cout << "Carteira " << i+1 << endl;
                cout << "Endereco " << carteiras[i]->get_endereco() << endl;
                cout << "Saldo btc " << carteiras[i]->get_saldoBtc() << endl;
                cout << "Saldo eth " << carteiras[i]->get_saldoEth() << endl;
                cout << "Saldo brl " << carteiras[i]->get_saldobrl() << endl;
                cout << endl;
            }
        }

        Carteira* get_carteira_by_endereco(string endereco) {  // Metodo feito pelo chat para me ajudar a arrumar o problema da chamada do metodo na main
            for (Carteira* c : carteiras) {
                if (c->get_endereco() == endereco) {
                    return c;
                }
            }
            return nullptr;
        }

};  

int main() {
    Exchange sistema;
    string endereco, tipo, moeda;
    double quantia, quantidade;

    Carteira* carteira = nullptr;  // Movendo a declaração para fora do switch.

    while (true) {
        cout << "\n---MENU---" << endl;
        cout << "1. Criar nova carteira" << endl;
        cout << "2. Depositar BRL" << endl;
        cout << "3. Realizar transacao" << endl;
        cout << "4. Exibir carteiras" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o endereco da carteira: ";
                cin >> endereco;
                sistema.adicionar_carteira(endereco);
                break;

            case 2:
                cout << "Digite o endereco da carteira para deposito: ";
                cin >> endereco;
                cout << "Digite o valor a ser depositado: ";
                cin >> quantia;
                sistema.depositar_brl(endereco, quantia);
                break;

            case 3:
                cout << "Digite o endereco da carteira para realizar a transacao: ";
                cin >> endereco;
                cout << "Digite o tipo de transacao (COMPRA/VENDA): ";
                cin >> tipo;
                cout << "Digite a moeda (BTC/ETH): ";
                cin >> moeda;
                cout << "Digite a quantidade: ";
                cin >> quantidade;

                carteira = sistema.get_carteira_by_endereco(endereco);
                if (carteira != nullptr) {
                    sistema.realizar_transacao(tipo, moeda, quantidade, carteira);
                } else {
                    cout << "Carteira nao encontrada!" << endl;
                }
                break;

            case 4:
                sistema.exibir_carteiras();
                break;

            case 5:
                cout << "Saindo..." << endl;
                return 0;

            default:
                cout << "Opcao invalida!" << endl;
                break;
        }
    }

    return 0;
}
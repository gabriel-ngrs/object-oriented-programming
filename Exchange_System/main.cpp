#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Para std::setprecision

using namespace std;

// Classe que representa uma carteira de criptomoedas
class Carteira {
private:
    string endereco; // Endereço da carteira
    float saldo_btc; // Saldo em Bitcoin
    float saldo_eth; // Saldo em Ethereum
    float saldo_brl; // Saldo em Reais

public:
    // Construtor da carteira
    Carteira(const string& endereco, float saldo_btc, float saldo_eth, float saldo_brl) 
        : endereco(endereco), saldo_btc(saldo_btc), saldo_eth(saldo_eth), saldo_brl(saldo_brl) {}

    // Método para alterar os saldos da carteira
    void alterar_saldo(float btc, float eth, float brl) {
        saldo_btc += btc;
        saldo_eth += eth;
        saldo_brl += brl;
    }

    // Método para exibir os saldos da carteira
    void exibir_saldo() const {
        cout << "Carteira " << endereco << ":\n";
        cout << "BTC: " << fixed << setprecision(4) << saldo_btc << "\n";
        cout << "ETH: " << fixed << setprecision(4) << saldo_eth << "\n";
        cout << "BRL: " << fixed << setprecision(2) << saldo_brl << "\n";
    }

    // Métodos getters para acessar os saldos e o endereço
    float get_saldo_btc() const { return saldo_btc; }
    float get_saldo_eth() const { return saldo_eth; }
    float get_saldo_brl() const { return saldo_brl; }
    const string& get_endereco() const { return endereco; }
};

// Classe que representa uma transação entre carteiras
class Transacao {
private:
    string tipo; // Tipo da transação (COMPRA ou VENDA)
    float quantidade; // Quantidade de criptomoeda
    float preco_unitario; // Preço unitário da criptomoeda
    Carteira* carteira_origem; // Carteira de origem
    Carteira* carteira_destino; // Carteira de destino

public:
    // Construtor da transação
    Transacao(const string& tipo, float quantidade, float preco_unitario, Carteira* origem, Carteira* destino) 
        : tipo(tipo), quantidade(quantidade), preco_unitario(preco_unitario), 
          carteira_origem(origem), carteira_destino(destino) {}

    // Método para calcular o valor total da transação
    float calcular_valor_total() const {
        return quantidade * preco_unitario;
    }

    // Método para executar a transação
    bool executar_transacao() {
        float total = calcular_valor_total();

        if (tipo == "COMPRA") {
            // Verifica se há saldo suficiente em BRL
            if (carteira_origem->get_saldo_brl() < total) {
                cout << "Transacao falhou: saldo BRL insuficiente.\n";
                return false;
            }
            // Atualiza os saldos
            carteira_origem->alterar_saldo(0, 0, -total);
            carteira_destino->alterar_saldo(quantidade, 0, 0);
        } else if (tipo == "VENDA") {
            // Verifica se há saldo suficiente em ETH
            if (carteira_origem->get_saldo_eth() < quantidade) {
                cout << "Transacao falhou: saldo ETH insuficiente.\n";
                return false;
            }
            // Atualiza os saldos
            carteira_origem->alterar_saldo(0, -quantidade, 0);
            carteira_destino->alterar_saldo(0, 0, total);
        }

        cout << "Transacao realizada com sucesso!\n";
        return true;
    }

    // Método para exibir detalhes da transação
    void exibir_detalhes() const {
        cout << "Transacao: " << tipo << " " << quantidade << " BTC/ETH a " << preco_unitario << " BRL\n";
        cout << "Origem: " << carteira_origem->get_endereco() << "\n";
        cout << "Destino: " << carteira_destino->get_endereco() << "\n";
    }
};

// Classe que representa a exchange
class Exchange {
private:
    vector<Carteira*> carteiras; // Lista de carteiras
    vector<Transacao*> transacoes; // Lista de transações

public:
    // Destrutor para liberar memória
    ~Exchange() {
        for (Carteira* carteira : carteiras) {
            delete carteira;
        }
        for (Transacao* transacao : transacoes) {
            delete transacao;
        }
    }

    // Método para adicionar uma nova carteira
    void adicionar_carteira(Carteira* carteira) {
        carteiras.push_back(carteira);
    }

    // Método para realizar uma transação
    void realizar_transacao(Transacao* transacao) {
        transacoes.push_back(transacao);
        transacao->executar_transacao();
    }

    // Método para exibir todas as carteiras
    void exibir_carteiras() const {
        for (const Carteira* carteira : carteiras) {
            carteira->exibir_saldo();
        }
    }
};

int main() {
    // Criação de 3 carteiras com saldos iniciais diferentes
    Carteira* carteira1 = new Carteira("carteira1", 1.0000, 2.0000, 5000.00);
    Carteira* carteira2 = new Carteira("carteira2", 1.0000, 2.0000, 5000.00);
    Carteira* carteira3 = new Carteira("carteira3", 1.0000, 2.0000, 5000.00);

    Exchange exchange; // Criação da exchange
    exchange.adicionar_carteira(carteira1);
    exchange.adicionar_carteira(carteira2);
    exchange.adicionar_carteira(carteira3);

    // Exibição dos saldos iniciais
    cout << "=== Estado Inicial das Carteiras ===\n";
    exchange.exibir_carteiras();
    cout << endl;

    // Realização de transações
    cout << "=== Realizando Transacoes ===\n";
    cout << endl;

    // Transação 1: Compra de 0.5 BTC na carteira 1
    Transacao* transacao1 = new Transacao("COMPRA", 0.5, 20000.00, carteira1, carteira2);
    cout << "Transacao 1: Compra de 0.5 BTC\n";
    exchange.realizar_transacao(transacao1);
    cout << endl;

    // Transação 2: Venda de 1 ETH na carteira 2
    Transacao* transacao2 = new Transacao("VENDA", 1.0, 3000.00, carteira2, carteira3);
    cout << "Transacao 2: Venda de 1 ETH\n";
    exchange.realizar_transacao(transacao2);
    cout << endl;

    // Transação 3: Tentativa de compra com saldo insuficiente na carteira 1
    Transacao* transacao3 = new Transacao("COMPRA", 0.5, 20000.00, carteira1, carteira2);
    cout << "Transacao 3: Tentativa de Compra de 0.5 BTC (saldo insuficiente)\n";
    exchange.realizar_transacao(transacao3);
    cout << endl;

    // Transação 4: Venda com quantidade maior que o disponível na carteira 2
    Transacao* transacao4 = new Transacao("VENDA", 10.0, 3000.00, carteira2, carteira1);
    cout << "Transacao 4: Tentativa de Venda de 10 ETH (quantidade maior que o disponivel)\n";
    exchange.realizar_transacao(transacao4);
    cout << endl;
    
    // Exibição dos saldos finais
    cout << "=== Estado Final das Carteiras ===\n";
    exchange.exibir_carteiras();
    cout << endl;
    return 0;
}
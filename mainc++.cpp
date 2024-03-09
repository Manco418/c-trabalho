#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Produto {
    string nome;
    int quantidade;
    float preco;
};

struct Cliente {
    string nome;
    string endereco;
};

vector<Produto> estoque;
vector<Cliente> clientes;

void inserirProduto() {
    Produto novoProduto;
    cout << "Nome do produto: ";
    cin >> novoProduto.nome;
    cout << "Quantidade: ";
    cin >> novoProduto.quantidade;
    cout << "Preço: ";
    cin >> novoProduto.preco;
    estoque.push_back(novoProduto);
    cout << "Produto inserido com sucesso!" << endl;
}

void listarProdutos() {
    cout << "Lista de Produtos:" << endl;
    for (int i = 0; i < estoque.size(); ++i) {
        cout << i << ": " << estoque[i].nome << ", Quantidade: " << estoque[i].quantidade << ", Preço: " << estoque[i].preco << endl;
    }
}

void pesquisarProduto() {
    string nome;
    cout << "Nome do produto: ";
    cin >> nome;
    for (int i = 0; i < estoque.size(); ++i) {
        if (estoque[i].nome == nome) {
            cout << "Produto encontrado:" << endl;
            cout << "Nome: " << estoque[i].nome << ", Quantidade: " << estoque[i].quantidade << ", Preço: " << estoque[i].preco << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void alterarProduto() {
    string nome;
    cout << "Nome do produto: ";
    cin >> nome;
    for (int i = 0; i < estoque.size(); ++i) {
        if (estoque[i].nome == nome) {
            cout << "Novos dados do produto:" << endl;
            cout << "Quantidade: ";
            cin >> estoque[i].quantidade;
            cout << "Preço: ";
            cin >> estoque[i].preco;
            cout << "Produto alterado com sucesso!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void removerProduto() {
    string nome;
    cout << "Nome do produto: ";
    cin >> nome;
    for (int i = 0; i < estoque.size(); ++i) {
        if (estoque[i].nome == nome) {
            estoque.erase(estoque.begin() + i);
            cout << "Produto removido com sucesso!" << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

void inserirCliente() {
    Cliente novoCliente;
    cout << "Nome do cliente: ";
    cin >> novoCliente.nome;
    cout << "Endereço: ";
    cin >> novoCliente.endereco;
    clientes.push_back(novoCliente);
    cout << "Cliente inserido com sucesso!" << endl;
}

void listarClientes() {
    cout << "Lista de Clientes:" << endl;
    for (int i = 0; i < clientes.size(); ++i) {
        cout << i << ": " << clientes[i].nome << ", Endereço: " << clientes[i].endereco << endl;
    }
}

void menu() {
    cout << "\n==== Menu ====" << endl;
    cout << "1. Inserir Produto" << endl;
    cout << "2. Listar Todos os Produtos" << endl;
    cout << "3. Pesquisar Produto" << endl;
    cout << "4. Alterar Produto" << endl;
    cout << "5. Remover Produto" << endl;
    cout << "6. Inserir Cliente" << endl;
    cout << "7. Listar Todos os Clientes" << endl;
    cout << "8. Sair" << endl;
    cout << "==============" << endl;
}

int main() {
    int opcao;
    do {
        menu();
        cout << "Escolha uma opção: ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                inserirProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                pesquisarProduto();
                break;
            case 4:
                alterarProduto();
                break;
            case 5:
                removerProduto();
                break;
            case 6:
                inserirCliente();
                break;
            case 7:
                listarClientes();
                break;
            case 8:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    } while (opcao != 8);
    return 0;
}

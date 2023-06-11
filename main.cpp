#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
};

struct Cliente {
    int codigo;
    string nome;
    string endereco;
};

struct Compra {
    int codigoProduto;
    int codigoCliente;
    int quantidade;
};

// Função para cadastrar um produto
void cadastrarProduto(vector<Produto>& produtos) {
    Produto produto;
    cout << "Digite o código do produto: ";
    cin >> produto.codigo;
    cout << "Digite o nome do produto: ";
    cin >> produto.nome;
    cout << "Digite o preço do produto: ";
    cin >> produto.preco;
    produtos.push_back(produto);
    cout << "Produto cadastrado com sucesso!" << endl;
}

// Função para buscar todos os produtos
void buscarTodosProdutos(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }
    cout << "Lista de produtos cadastrados:" << endl;
    for (const Produto& produto : produtos) {
        cout << "Código: " << produto.codigo << ", Nome: " << produto.nome << ", Preço: " << produto.preco << endl;
    }
}

// Função para buscar um produto por código
void buscarProdutoPorCodigo(const vector<Produto>& produtos) {
    int codigo;
    cout << "Digite o código do produto: ";
    cin >> codigo;
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo) {
            cout << "Produto encontrado:" << endl;
            cout << "Código: " << produto.codigo << ", Nome: " << produto.nome << ", Preço: " << produto.preco << endl;
            return;
        }
    }
    cout << "Produto não encontrado." << endl;
}

// Função para cadastrar um cliente
void cadastrarCliente(vector<Cliente>& clientes) {
    Cliente cliente;
    cout << "Digite o código do cliente: ";
    cin >> cliente.codigo;
    cout << "Digite o nome do cliente: ";
    cin >> cliente.nome;
    cout << "Digite o endereço do cliente: ";
    cin.ignore();
    getline(cin, cliente.endereco);
    clientes.push_back(cliente);
    cout << "Cliente cadastrado com sucesso!" << endl;
}

// Função para buscar todos os clientes
void buscarTodosClientes(const vector<Cliente>& clientes) {
    if (clientes.empty()) {
        cout << "Nenhum cliente cadastrado." << endl;
        return;
    }
    cout << "Lista de clientes cadastrados:" << endl;
    for (const Cliente& cliente : clientes) {
        cout << "Código: " << cliente.codigo << ", Nome: " << cliente.nome << ", Endereço: " << cliente.endereco << endl;
    }
}

// Função para buscar um cliente por código
void buscarClientePorCodigo(const vector<Cliente>& clientes) {
    int codigo;
    cout << "Digite o código do cliente: ";
    cin >> codigo;
    for (const Cliente& cliente : clientes) {
        if (cliente.codigo == codigo) {
            cout << "Cliente encontrado:" << endl;
            cout << "Código: " << cliente.codigo << ", Nome: " << cliente.nome << ", Endereço: " << cliente.endereco << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
}

// Função para realizar uma compra
void realizarCompra(const vector<Produto>& produtos, const vector<Cliente>& clientes, vector<Compra>& compras) {
    Compra compra;
    cout << "Digite o código do produto: ";
    cin >> compra.codigoProduto;
    cout << "Digite o código do cliente: ";
    cin >> compra.codigoCliente;
    cout << "Digite a quantidade: ";
    cin >> compra.quantidade;
    compras.push_back(compra);
    cout << "Compra realizada com sucesso!" << endl;
}

// Função para exibir todas as compras
void exibirCompras(const vector<Compra>& compras, const vector<Produto>& produtos, const vector<Cliente>& clientes) {
    if (compras.empty()) {
        cout << "Nenhuma compra realizada." << endl;
        return;
    }
    cout << "Lista de compras realizadas:" << endl;
    for (const Compra& compra : compras) {
        cout << "Produto: ";
        auto itProduto = find_if(produtos.begin(), produtos.end(), [&](const Produto& p) {
            return p.codigo == compra.codigoProduto;
        });
        if (itProduto != produtos.end()) {
            cout << "Código: " << itProduto->codigo << ", Nome: " << itProduto->nome << ", Preço: " << itProduto->preco;
        } else {
            cout << "Produto não encontrado";
        }
        
        cout << " | Cliente: ";
        auto itCliente = find_if(clientes.begin(), clientes.end(), [&](const Cliente& c) {
            return c.codigo == compra.codigoCliente;
        });
        if (itCliente != clientes.end()) {
            cout << "Código: " << itCliente->codigo << ", Nome: " << itCliente->nome << ", Endereço: " << itCliente->endereco;
        } else {
            cout << "Cliente não encontrado";
        }
        
        cout << " | Quantidade: " << compra.quantidade << endl;
    }
}

int main() {
    vector<Produto> produtos;
    vector<Cliente> clientes;
    vector<Compra> compras;
    int opcao;
    
    do {
        cout << "=== Sistema de Compra de Produtos ===" << endl;
        cout << "1. Cadastrar produto" << endl;
        cout << "2. Buscar todos os produtos" << endl;
        cout << "3. Buscar produto por código" << endl;
        cout << "4. Cadastrar cliente" << endl;
        cout << "5. Buscar todos os clientes" << endl;
        cout << "6. Buscar cliente por código" << endl;
        cout << "7. Realizar compra" << endl;
        cout << "8. Exibir todas as compras" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite uma opção: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                cadastrarProduto(produtos);
                break;
            case 2:
                buscarTodosProdutos(produtos);
                break;
            case 3:
                buscarProdutoPorCodigo(produtos);
                break;
            case 4:
                cadastrarCliente(clientes);
                break;
            case 5:
                buscarTodosClientes(clientes);
                break;
            case 6:
                buscarClientePorCodigo(clientes);
                break;
            case 7:
                realizarCompra(produtos, clientes, compras);
                break;
            case 8:
                exibirCompras(compras, produtos, clientes);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
        
        cout << endl;
        
    } while (opcao != 0);

    return 0;
}



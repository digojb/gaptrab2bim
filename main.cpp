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
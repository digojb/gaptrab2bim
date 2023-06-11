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



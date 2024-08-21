#include <iostream>
#include <vector>

using namespace std;

struct Item {
    string nome;
    int quantidade;
};

void adicionarItem(vector<Item>& estoque) {
    Item item;
    cout << "Digite o nome do item: ";
    cin >> item.nome;
    cout << "Digite a quantidade do item: ";
    cin >> item.quantidade;
    estoque.push_back(item);
    cout << "Item adicionado com sucesso!" << endl;
}

void removerItem(vector<Item>& estoque) {
    string nome;
    int qtdeRemover;
    cout << "Digite o nome do item que deseja remover: ";
    cin >> nome;
    cout << "Digite a quantidade a remover: ";
    cin >> qtdeRemover;

    for (auto it = estoque.begin(); it != estoque.end(); ++it) {
        if (it->nome == nome) {
            if (it->quantidade > qtdeRemover) {
                it->quantidade -= qtdeRemover;
                cout << "Quantidade atualizada. Restam " << it->quantidade << " no estoque." << endl;
            } else if (it->quantidade == qtdeRemover) {
                estoque.erase(it);
                cout << "Item removido completamente do estoque." << endl;
            } else {
                cout << "Quantidade solicitada para remover excede a disponível no estoque." << endl;
            }
            return;
        }
    }
    cout << "Item nao encontrado no estoque." << endl;
}

void visualizarEstoque(const vector<Item>& estoque) {
    cout << "Estoque atual:" << endl;
    for (const auto& item : estoque) {
        cout << "Nome: " << item.nome << ", Quantidade: " << item.quantidade << endl;
    }
}

int main() {
    vector<Item> estoque;
    int opcao;

    do {
        cout << "Selecione uma opcao:" << endl;
        cout << "1. Adicionar item" << endl;
        cout << "2. Remover item" << endl;
        cout << "3. Visualizar estoque" << endl;
        cout << "0. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarItem(estoque);
                break;
            case 2:
                removerItem(estoque);
                break;
            case 3:
                visualizarEstoque(estoque);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}

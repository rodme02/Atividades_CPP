#include <iostream>
using namespace std;

int main() {
    int matriz[3][3];
    int soma = 0;

    // Solicita ao usuário para inserir os elementos da matriz
    cout << "Insira os elementos da matriz 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Calcula a soma dos elementos na diagonal principal
    for (int i = 0; i < 3; i++) {
        soma += matriz[i][i];
    }

    // Exibe a soma
    cout << "A soma dos elementos na diagonal principal eh: " << soma << endl;

    return 0;
}
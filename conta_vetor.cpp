#include <iostream>
using namespace std;

int main() {
    int vetor[5];
    int soma = 0;

    cout << "Insira 5 numeros no vetor:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> vetor[i];
        soma += vetor[i];
    }

    cout << "A soma dos numeros eh: " << soma << endl;

    return 0;
}
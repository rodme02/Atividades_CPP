#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros(10);

    cout << "Insira 10 numeros:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    int maior = numeros[0];
    for (int i = 1; i < 10; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }

    cout << "O maior numero eh " << maior << endl;

    return 0;
}
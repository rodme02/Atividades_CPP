#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Erro: Insira ao menos um numero para ordenar." << endl;
        return 1;
    }
    int n = argc - 1;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    
    bubbleSort(arr, n);
    
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <chrono>

// Função para somar os elementos de uma matriz alocada dinamicamente
long long somaMatrizDinamica(int** matriz, int N) {
    long long soma = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

// Função para somar os elementos de uma matriz usando std::vector
long long somaMatrizVector(const std::vector<std::vector<int>>& matriz) {
    long long soma = 0;
    for (const auto& linha : matriz) {
        for (int valor : linha) {
            soma += valor;
        }
    }
    return soma;
}

int main() {
    int N = 1000;  // Tamanho da matriz N x N

    // Alocação dinâmica de memória para uma matriz N x N
    int** matriz = new int*[N];
    for (int i = 0; i < N; ++i) {
        matriz[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = 1;  // Preenche com o valor 1 para simplificar
        }
    }

    // Medição do tempo de soma para a matriz dinâmica
    auto start = std::chrono::high_resolution_clock::now();
    long long somaDinamica = somaMatrizDinamica(matriz, N);
    auto stop = std::chrono::high_resolution_clock::now();
    auto durationDinamica = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Tempo com alocacao dinamica manual: " << durationDinamica.count() << " ms" << std::endl;

    // Liberação da memória
    for (int i = 0; i < N; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    // Uso de std::vector para a matriz
    std::vector<std::vector<int>> matrizVector(N, std::vector<int>(N, 1));

    // Medição do tempo de soma para a matriz com std::vector
    start = std::chrono::high_resolution_clock::now();
    long long somaVector = somaMatrizVector(matrizVector);
    stop = std::chrono::high_resolution_clock::now();
    auto durationVector = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Tempo com std::vector: " << durationVector.count() << " ms" << std::endl;

    return 0;
}

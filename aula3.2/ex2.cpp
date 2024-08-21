#include <iostream>
#include <vector>

// Classe Matriz para representar uma matriz quadrada
class Matriz {
public:
    // Construtor que inicializa uma matriz quadrada de dimensão N x N
    Matriz(int N) : data(N, std::vector<int>(N, 0)) {}

    // Método para acessar um elemento específico da matriz (leitura)
    int get(int i, int j) const {
        return data[i][j];
    }

    // Método para modificar um elemento específico da matriz (escrita)
    void set(int i, int j, int valor) {
        data[i][j] = valor;
    }

    // Método para imprimir a matriz
    void imprime() const {
        for (const auto& linha : data) {
            for (int valor : linha) {
                std::cout << valor << " ";
            }
            std::cout << std::endl;
        }
    }

    // Método para acessar o tamanho da matriz
    int tamanho() const {
        return data.size();
    }

private:
    std::vector<std::vector<int>> data;  // Armazena os elementos da matriz
};

// Função que multiplica duas matrizes A e B, armazenando o resultado em C
void multiplicaMatriz(const Matriz& A, const Matriz& B, Matriz& C) {
    int N = A.tamanho();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int soma = 0;
            for (int k = 0; k < N; k++) {
                soma += A.get(i, k) * B.get(k, j);
            }
            C.set(i, j, soma);
        }
    }
}

int main() {
    int N = 3;

    Matriz A(N), B(N), C(N);

    // Preenchendo a matriz A
    A.set(0, 0, 1); A.set(0, 1, 2); A.set(0, 2, 3);
    A.set(1, 0, 4); A.set(1, 1, 5); A.set(1, 2, 6);
    A.set(2, 0, 7); A.set(2, 1, 8); A.set(2, 2, 9);

    // Preenchendo a matriz B
    B.set(0, 0, 9); B.set(0, 1, 8); B.set(0, 2, 7);
    B.set(1, 0, 6); B.set(1, 1, 5); B.set(1, 2, 4);
    B.set(2, 0, 3); B.set(2, 1, 2); B.set(2, 2, 1);

    // Multiplica as matrizes A e B, armazenando o resultado em C
    multiplicaMatriz(A, B, C);

    // Imprime a matriz resultante C
    C.imprime();

    return 0;
}

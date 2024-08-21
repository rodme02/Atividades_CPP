#include <iostream>
#include <algorithm>  // Para std::copy

class Vector {
public:
    // Construtor
    Vector(int tamanho) : capacidade(tamanho), tam(0), dados(new int[capacidade]) {}

    // Destruidor
    ~Vector() {
        delete[] dados;
    }

    // Inicializa todos os elementos do vetor com um valor específico
    void inicializa(int valor) {
        for (int i = 0; i < capacidade; i++) {
            dados[i] = valor;
        }
        tam = capacidade;
    }

    // Retorna o valor no índice especificado (inline para acesso rápido)
    inline int get(int index) const {
        return dados[index];
    }

    // Define o valor em um índice específico (inline para modificação rápida)
    inline void set(int index, int valor) {
        if (index >= 0 && index < tam) {
            dados[index] = valor;
        }
    }

    // Insere um valor em um índice específico
    void inserir(int index, int valor) {
        if (tam == capacidade) {
            redimensiona(capacidade * 2);
        }
        if (index >= 0 && index <= tam) {
            for (int i = tam; i > index; i--) {
                dados[i] = dados[i - 1];
            }
            dados[index] = valor;
            tam++;
        }
    }

    // Remove um elemento em um índice específico
    void remover(int index) {
        if (index >= 0 && index < tam) {
            for (int i = index; i < tam - 1; i++) {
                dados[i] = dados[i + 1];
            }
            tam--;
        }
    }

    // Imprime todos os elementos do vetor
    void imprime() const {
        for (int i = 0; i < tam; i++) {
            std::cout << dados[i] << " ";
        }
        std::cout << std::endl;
    }

    // Multiplica cada elemento do vetor por um escalar
    void multiplicaEscalar(int escalar) {
        for (int i = 0; i < tam; i++) {
            dados[i] *= escalar;
        }
    }

private:
    int* dados;
    int tam;
    int capacidade;

    // Redimensiona o vetor para uma nova capacidade
    void redimensiona(int novaCapacidade) {
        int* novoDados = new int[novaCapacidade];
        std::copy(dados, dados + tam, novoDados);
        delete[] dados;
        dados = novoDados;
        capacidade = novaCapacidade;
    }
};

int main() {
    Vector vec(5);
    vec.inicializa(10);
    vec.imprime();
    
    vec.set(0, 5);
    vec.inserir(2, 15);
    vec.remover(1);
    vec.imprime();
    
    vec.multiplicaEscalar(3);
    vec.imprime();

    return 0;
}
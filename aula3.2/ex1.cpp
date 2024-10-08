#include <iostream>   // Inclui a biblioteca padrão de entrada e saída, usada para operações como std::cout.
#include <fstream>    // Inclui a biblioteca para manipulação de arquivos, usada para ler e escrever arquivos.
#include <vector>     // Inclui a biblioteca de vetores, usada para armazenar e manipular listas de números.

// Declaração de funções:

// Função que lê números de um arquivo e os armazena em um vetor.
void lerArquivo(const std::string& nomeArquivo, std::vector<int>& numeros);

// Função que dobra os valores de um vetor de números, passando o vetor original por referência.
void dobrarValoresReferencia(const std::vector<int>& numerosOriginais, std::vector<int>& numerosDobrados);

// Função que dobra os valores de um vetor de números, passando o vetor original por ponteiro.
void dobrarValoresPonteiro(const std::vector<int>* numerosOriginais, std::vector<int>* numerosDobrados);

// Função que escreve os números de um vetor em um arquivo.
void escreverArquivo(const std::string& nomeArquivo, const std::vector<int>& numeros);

// Implementação das funções...

int main() {
    // Declaração de dois vetores de inteiros: um para armazenar os números lidos do arquivo e outro para armazenar os números dobrados.
    std::vector<int> numeros, numerosDobrados;

    // Chama a função para ler os números do arquivo "entrada.txt" e armazena-os no vetor 'numeros'.
    lerArquivo("entrada.txt", numeros);

    // Chama a função que dobra os valores do vetor 'numeros' usando passagem por referência e armazena o resultado no vetor 'numerosDobrados'.
    dobrarValoresReferencia(numeros, numerosDobrados);

    // Chama a função que escreve os números do vetor 'numerosDobrados' no arquivo "saida_referencia.txt".
    escreverArquivo("saida_referencia.txt", numerosDobrados);

    // Chama a função que dobra os valores do vetor 'numeros' usando passagem por ponteiro e armazena o resultado no vetor 'numerosDobrados'.
    dobrarValoresPonteiro(&numeros, &numerosDobrados);

    // Chama a função que escreve os números do vetor 'numerosDobrados' no arquivo "saida_ponteiro.txt".
    escreverArquivo("saida_ponteiro.txt", numerosDobrados);

    // Retorna 0, indicando que o programa terminou com sucesso.
    return 0;
}

void lerArquivo(const std::string& nomeArquivo, std::vector<int>& numeros) {
    // Abre o arquivo para leitura.
    std::ifstream arquivo(nomeArquivo);

    // Verifica se o arquivo foi aberto corretamente.
    if (arquivo.is_open()) {
        int numero;

        // Enquanto houver números para ler no arquivo, armazena-os no vetor 'numeros'.
        while (arquivo >> numero) {
            numeros.push_back(numero);
        }

        // Fecha o arquivo após a leitura.
        arquivo.close();
    } else {
        // Se houve um erro ao abrir o arquivo, exibe uma mensagem de erro.
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
    }
}

void dobrarValoresReferencia(const std::vector<int>& numerosOriginais, std::vector<int>& numerosDobrados) {
    // Limpa o vetor 'numerosDobrados' para garantir que esteja vazio antes de adicionar os novos valores.
    numerosDobrados.clear();

    // Para cada número no vetor 'numerosOriginais', dobra o valor e adiciona ao vetor 'numerosDobrados'.
    for (int numero : numerosOriginais) {
        numerosDobrados.push_back(numero * 2);
    }
}

void dobrarValoresPonteiro(const std::vector<int>* numerosOriginais, std::vector<int>* numerosDobrados) {
    // Limpa o vetor 'numerosDobrados' para garantir que esteja vazio antes de adicionar os novos valores.
    numerosDobrados->clear();

    // Verifica se o ponteiro para o vetor de números originais é válido.
    if (numerosOriginais != nullptr) {
        // Para cada número no vetor apontado por 'numerosOriginais', dobra o valor e adiciona ao vetor apontado por 'numerosDobrados'.
        for (int numero : *numerosOriginais) {
            numerosDobrados->push_back(numero * 2);
        }
    }
}

void escreverArquivo(const std::string& nomeArquivo, const std::vector<int>& numeros) {
    // Abre o arquivo para escrita.
    std::ofstream arquivo(nomeArquivo);

    // Verifica se o arquivo foi aberto corretamente.
    if (arquivo.is_open()) {
        // Para cada número no vetor 'numeros', escreve o número no arquivo.
        for (int numero : numeros) {
            arquivo << numero << std::endl;
        }

        // Fecha o arquivo após a escrita.
        arquivo.close();
    } else {
        // Se houve um erro ao abrir o arquivo, exibe uma mensagem de erro.
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << " para escrita" << std::endl;
    }
}
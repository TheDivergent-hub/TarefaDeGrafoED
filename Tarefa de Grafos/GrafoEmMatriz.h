#ifndef GRAFOEMMATRIZ_H
#define GRAFOEMMATRIZ_H

#include <vector>
#include <string>

class GrafoEmMatriz {
public:
    GrafoEmMatriz(int numVertices);
    void adicionarAresta(int v1, int v2);
    void imprimirGrafo();
    void carregarGrafoDeArquivo(const std::string& nomeArquivo);
    void buscaEmLargura(int s, int t);
    void buscaEmProfundidadeComPilha(int s, int t);

private:
    int numVertices;
    std::vector<std::vector<int>> matrizAdjacencia;
};

#endif

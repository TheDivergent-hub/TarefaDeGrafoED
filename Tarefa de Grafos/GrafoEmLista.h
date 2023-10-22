#ifndef GRAFOEMLISTA_H
#define GRAFOEMLISTA_H

#include <vector>
#include <list>
#include <string>
#include <iostream>

class GrafoEmLista {
public:
    GrafoEmLista(int numVertices);
    void adicionarAresta(int v1, int v2);
    void imprimirGrafo();
    void carregarGrafoDeArquivo(const std::string& nomeArquivo, GrafoEmLista& grafo);
    void buscaEmLargura(int s, int t);
    void buscaEmProfundidadeComPilha(int s, int t);

private:
    int numVertices;
    std::vector<std::list<int>> listaAdjacencia;
};

#endif

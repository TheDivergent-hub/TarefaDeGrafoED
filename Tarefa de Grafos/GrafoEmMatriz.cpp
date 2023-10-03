#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
#include "Pilha.h"
#include "GrafoEmMatriz.h"

using namespace std;

class GrafoEmMatriz {

public:

    GrafoEmMatriz(int numVertices);
    void adicionarAresta(int v1, int v2);
    void imprimirGrafo();
    void carregarGrafoDeArquivo(const string& nomeArquivo);
    void buscaEmLargura(int s, int t);
    void buscaEmProfundidadeComPilha(int s, int t);


private:

    vector<vector<int>> matrizAdjacencia;
    int numVertices;
    
};


GrafoEmMatriz::GrafoEmMatriz(int numVertices) {
    
    this->numVertices = numVertices;
    matrizAdjacencia.resize(numVertices, vector<int>(numVertices, 0));

}


void GrafoEmMatriz::adicionarAresta(int v1, int v2) {

    matrizAdjacencia[v1][v2] = 1;

}


void GrafoEmMatriz::imprimirGrafo() {

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << matrizAdjacencia[i][j] << " ";
        }
        cout << endl;
    }

}

void GrafoEmMatriz::carregarGrafoDeArquivo(const string& nomeArquivo) {

    ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    int v1, v2;
    string linha;

    while (getline(arquivo, linha)) {
        istringstream streamLinha(linha);
        streamLinha >> v1 >> v2;
        adicionarAresta(v1, v2);
    }

    arquivo.close();

}

void GrafoEmMatriz::buscaEmLargura(int s, int t) {

    vector<bool> visitado(numVertices, false);
    unordered_map<int, int> pai; // Mapeia vértices pais

    queue<int> fila;
    fila.push(s);
    visitado[s] = true;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (int v = 0; v < numVertices; v++) {
            if (matrizAdjacencia[u][v] == 1 && !visitado[v]) {
                visitado[v] = true;
                fila.push(v);
                pai[v] = u; // Vértice 'u' é pai de 'v'
            }
        }
    }

    // Recupere e imprima o caminho
    if (!visitado[t]) {
        cout << "Não há caminho entre os vértices " << s << " e " << t << "." << endl;
    } else {
        vector<int> caminho;
        int v = t;
        while (v != s) {
            caminho.push_back(v);
            v = pai[v];
        }
        caminho.push_back(s);

        cout << "Caminho entre os vértices " << s << " e " << t << ": ";
        for (int i = caminho.size() - 1; i >= 0; i--) {
            cout << caminho[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }

}

void GrafoEmMatriz::buscaEmProfundidadeComPilha(int s, int t) {

    vector<bool> visitado(numVertices, false);
    vector<int> pai(numVertices, -1); // Mapeia vértices pais

    Pilha pilha(numVertices); // Use a classe de pilha existente

    pilha.empilhar(s);
    visitado[s] = true;

    while (!pilha.vazia()) {
        int u = pilha.topo();
        pilha.desempilhar();

        if (u == t) {
            // Encontrou o destino, imprima o caminho
            cout << "Caminho entre os vértices " << s << " e " << t << ": ";
            int v = t;
            while (v != -1) {
                cout << v;
                v = pai[v];
                if (v != -1) cout << " -> ";
            }
            cout << endl;
            return;
        }

        for (int v = 0; v < numVertices; v++) {
            if (matrizAdjacencia[u][v] == 1 && !visitado[v]) {
                visitado[v] = true;
                pai[v] = u;
                pilha.empilhar(v);
            }
        }
    }

    cout << "Não há caminho entre os vértices " << s << " e " << t << "." << endl;
    
}


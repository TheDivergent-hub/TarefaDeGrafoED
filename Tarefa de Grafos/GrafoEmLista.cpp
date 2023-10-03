#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <list>
#include "Pilha.h"
#include "GrafoEmLista.h"

using namespace std;


struct Vertice {

    int dado;
    vector<int> vizinhos; 

};

vector<Vertice> vertices;

class GrafoEmLista {

 public:

    GrafoEmLista(int numVertices);
    void adicionarAresta(int v1, int v2);
    void imprimirGrafo();
    void carregarGrafoDeArquivo(const string& nomeArquivo, GrafoEmLista& grafo);
    void buscaEmLargura(int s, int t);
    void buscaEmProfundidadeComPilha(int s, int t);

 private:

    int numVertices;
    vector<list<int>> listaAdjacencia;

};


GrafoEmLista::GrafoEmLista(int numVertices) {

    vertices.resize(numVertices);
    for (int i = 0; i < numVertices; i++) {
        vertices[i].dado = 0;
    }

}


void GrafoEmLista::adicionarAresta(int v1, int v2) {

    vertices[v1].vizinhos.push_back(v2);
    vertices[v2].vizinhos.push_back(v1);

}


void GrafoEmLista::imprimirGrafo() {

    for (int i = 0; i < vertices.size(); i++) {
        cout << "Vértice " << vertices[i].dado << ": ";
        for (int j = 0; j < vertices[i].vizinhos.size(); j++) {
            cout << vertices[i].vizinhos[j] << " ";
        }
        cout << endl;
    }
    
}

void GrafoEmLista::carregarGrafoDeArquivo(const string& nomeArquivo, GrafoEmLista& grafo) {

    ifstream arquivo(nomeArquivo);
    
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    int v1, v2;
    string linha;

    while (getline(arquivo, linha)) {
        
        istringstream streamLinha(linha);
        streamLinha >> v1;
        
        while (streamLinha >> v2) {
            grafo.adicionarAresta(v1, v2);
        }

    }

    arquivo.close();
}

void GrafoEmLista::buscaEmLargura(int s, int t) {

    vector<bool> visitado(numVertices, false);
    unordered_map<int, int> pai; // Mapeia vértices pais

    queue<int> fila;
    fila.push(s);
    visitado[s] = true;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (int v : listaAdjacencia[u]) {
            if (!visitado[v]) {
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

void GrafoEmLista::buscaEmProfundidadeComPilha(int s, int t) {

    vector<bool> visitado(numVertices, false);
    vector<int> pai(numVertices, -1); // Mapeia vértices pais

    Pilha pilha(numVertices); // Crie uma instância da classe Pilha
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

        for (int v : listaAdjacencia[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                pai[v] = u;
                pilha.empilhar(v);
            }
        }
    }

    cout << "Não há caminho entre os vértices " << s << " e " << t << "." << endl;
}


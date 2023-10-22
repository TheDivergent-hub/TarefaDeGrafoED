#include "GrafoEmLista.h"
#include "GrafoEmMatriz.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    GrafoEmLista grafoLista(5); 
    grafoLista.carregarGrafoDeArquivo("exemploParaGrafoEmLista.txt", grafoLista);

    GrafoEmMatriz grafoMatriz(5);
    grafoMatriz.carregarGrafoDeArquivo("exemploParaGrafoEmMatriz.txt");

    int escolha;
    
    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Busca em Largura em Grafo em Lista" << endl;
        cout << "2. Busca em Profundidade em Grafo em Lista" << endl;
        cout << "3. Busca em Largura em Grafo em Matriz" << endl;
        cout << "4. Busca em Profundidade em Grafo em Matriz" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite o número da opção: ";
        cin >> escolha;

        switch (escolha) {

            case 1:
                
                int s, t;
                cout << "Digite o vértice de origem: ";
                cin >> s;
                cout << "Digite o vértice de destino: ";
                cin >> t;
                grafoLista.buscaEmLargura(s, t);
                break;

            case 2:
                
                cout << "Digite o vértice de origem: ";
                cin >> s;
                cout << "Digite o vértice de destino: ";
                cin >> t;
                grafoLista.buscaEmProfundidadeComPilha(s, t);
                break;

            case 3:
                
                cout << "Digite o vértice de origem: ";
                cin >> s;
                cout << "Digite o vértice de destino: ";
                cin >> t;
                grafoMatriz.buscaEmLargura(s, t);
                break;

            case 4:
                
                cout << "Digite o vértice de origem: ";
                cin >> s;
                cout << "Digite o vértice de destino: ";
                cin >> t;
                grafoMatriz.buscaEmProfundidadeComPilha(s, t);
                break;

            case 0:
                cout << "Programa encerrado." << endl;
                break;

            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }

    } while (escolha != 0);

    return 0;
}

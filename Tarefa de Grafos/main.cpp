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
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Busca em Largura em Grafo em Lista" << endl;
        cout << "2. Busca em Profundidade em Grafo em Lista" << endl;
        cout << "3. Busca em Largura em Grafo em Matriz" << endl;
        cout << "4. Busca em Profundidade em Grafo em Matriz" << endl;
        cout << "0. Sair" << endl;
        cout << "Digite o numero da opcao: ";
        cin >> escolha;
        

        switch (escolha) {

            case 1:
                
                int s, t;
                cout << "Digite o vertice de origem: ";
                cin >> s;
                cout << "Digite o vertice de destino: ";
                cin >> t;
                grafoLista.buscaEmLargura(s, t);
                break;

            case 2:
                
                cout << "Digite o vertice de origem: ";
                cin >> s;
                cout << "Digite o vertice de destino: ";
                cin >> t;
                grafoLista.buscaEmProfundidadeComPilha(s, t);
                break;

            case 3:
                
                cout << "Digite o vertice de origem: ";
                cin >> s;
                cout << "Digite o vertice de destino: ";
                cin >> t;
                grafoMatriz.buscaEmLargura(s, t);
                break;

            case 4:
                
                cout << "Digite o vertice de origem: ";
                cin >> s;
                cout << "Digite o vertice de destino: ";
                cin >> t;
                grafoMatriz.buscaEmProfundidadeComPilha(s, t);
                break;

            case 0:
                cout << "Programa encerrado." << endl;
                break;

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (escolha != 0);

    return 0;
}

/*
    Nota: Esse definitivamente foi o melhor switch case que já vi, não esperava que era possível ordenar os comandos do cout com ele e
    integrar outros comandos dentro dele, embora eu tenha usado muito do-while em Java, não consegui portar meus conhecimentos
    de lá para o c++ porque o Java em si é muito enrigecido, praticar Java por um ano e chegar agora e aplicar tudo de um outro
    jeito dá muita dor de cabeça. Prciso voltar a estudar o que as funções fazem.
*/
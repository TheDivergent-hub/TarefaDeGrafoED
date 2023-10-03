#include "Pilha.h"
#include <iostream>


Pilha::Pilha(int capacidade) {

    this->capacidade = capacidade;
    this->elementos = new int[capacidade];
    this->tamanhoAtual = 0;
}


Pilha::~Pilha() {

    delete[] elementos;

}


bool Pilha::vazia() const{

    return tamanhoAtual == 0;

}


bool Pilha::cheia() const{

    return tamanhoAtual == capacidade;

}

void Pilha::empilhar(int valor) {

    if (!cheia()) {
        elementos[tamanhoAtual] = valor;
        tamanhoAtual++;
    } else {
        std::cout << "A pilha está cheia. Não é possível empilhar." << std::endl;
    }

}


int Pilha::desempilhar() {

    if (!vazia()) {
        tamanhoAtual--;
        return elementos[tamanhoAtual];
    } else {
        std::cout << "A pilha está vazia. Não é possível desempilhar." << std::endl;
        return -1; 
    }

}


int Pilha::topo() const{

    if (!vazia()) {
        return elementos[tamanhoAtual - 1];
    } else {
        std::cout << "A pilha está vazia." << std::endl;
        return -1; 
    }

}


int Pilha::tamanho() const{

    return tamanhoAtual;

}
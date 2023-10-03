#ifndef _PILHA_H_
#define _PILHA_H_

class Pilha {
public:

    Pilha(int capacidade); 
    ~Pilha(); //  Nota: não é obrigatório, mas é uma boa prática? já existe o 'delete' independendemente dessa classe simples
    bool vazia() const;
    bool cheia() const;
    void empilhar(int valor);
    int desempilhar();
    int topo() const;
    int tamanho() const;

private:

    int* elementos; 
    int capacidade; 
    int tamanhoAtual; 

};

#endif

// Nota: Usar 'const' em funções que não alteram o estado (informações sobre o objeto e as que ele carrega) parece ser uma boa prática
// de programação para evitar modificações acidentais. Isso está ligado à injeção de código?

// Nota 2: ao que tudo indica, é um mecanismo de segurança que se aproveita da informação passada para o compilador sobre as 
// instruções da função para que a integridade do objeto gerado seja mantida.
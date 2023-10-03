# Compilador
CXX = g++

# Opções de compilação
CXXFLAGS = -std=c++11 -Wall

# Nome do executável para Grafo em Lista
EXEC_LISTA = grafo_lista

# Nome do executável para Grafo em Matriz
EXEC_MATRIZ = grafo_matriz

# Dependências comuns
DEPS = Pilha.h

all: $(EXEC_LISTA) $(EXEC_MATRIZ)

$(EXEC_LISTA): GrafoEmLista.cpp main.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) GrafoEmLista.cpp main.cpp -o $(EXEC_LISTA)

$(EXEC_MATRIZ): GrafoEmMatriz.cpp main.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) GrafoEmMatriz.cpp main.cpp -o $(EXEC_MATRIZ)

clean:
	rm -f $(EXEC_LISTA) $(EXEC_MATRIZ)

.PHONY: all clean

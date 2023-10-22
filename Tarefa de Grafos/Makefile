# Compilador
CXX = g++

# Opções de compilação
CXXFLAGS = -std=c++11 -Wall

# Nome do executável
EXECUTABLE = programa

# Dependências
DEPS = GrafoEmLista.cpp GrafoEmMatriz.cpp Pilha.cpp main.cpp Pilha.h GrafoEmLista.h GrafoEmMatriz.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(DEPS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean

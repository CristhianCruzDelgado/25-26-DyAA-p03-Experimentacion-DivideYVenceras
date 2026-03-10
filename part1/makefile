## Universidad de La Laguna
# Degree: Ingeniería Informática
# Signature: Diseño y Análisis de Algoritmos
# Practice 03: Experimentación con Divide y Vencerás
# Authors: 
#   Cristhian Adoney Cruz Delgado
#   Michelangelo Da Cruz Bochicchio
# Emails: 
#   alu0101648293@ull.edu.es
#   alu0101651217@ull.edu.es

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Iinclude

EXE = main

SRC = $(shell find . -name "*.cc")
OBJ = $(SRC:.cc=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -delete
	rm -f $(EXE)

.PHONY: clean

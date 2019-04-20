all: saida
	@echo " "
	@echo "Compilação concluída"
	@echo " "

saida: main.o Vertex.o Matrix.o List.o BreadthFirstSearch.o AdjacencyList.o AStar.o GeneticAlgorithm.o Animation.o
	g++ -o exe main.o Vertex.o Matrix.o List.o BreadthFirstSearch.o AdjacencyList.o AStar.o GeneticAlgorithm.o Animation.o

main.o: main.cpp
	g++ -o main.o -c main.cpp

Vertex.o: Vertex.cpp
	g++ -o Vertex.o -c Vertex.cpp

List.o: List.cpp
	g++ -o List.o -c List.cpp

BreadthFirstSearch.o: BreadthFirstSearch.cpp
	g++ -o BreadthFirstSearch.o -c BreadthFirstSearch.cpp

AStar.o: AStar.cpp
	g++ -o AStar.o -c AStar.cpp

Matrix.o: Matrix.cpp
	g++ -o Matrix.o -c Matrix.cpp

AdjacencyList.o: AdjacencyList.cpp
	g++ -o AdjacencyList.o -c AdjacencyList.cpp

GeneticAlgorithm.o: GeneticAlgorithm.cpp
	g++ -o GeneticAlgorithm.o -c GeneticAlgorithm.cpp

Animation.o: Animation.cpp
	g++ -o Animation.o -c Animation.cpp
clean: 
	rm -f *.o

execClean:
	rm -f exe

rebuildAndRun:
	make clean
	make execClean
	make
	./exe

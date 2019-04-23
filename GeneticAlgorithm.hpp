#pragma once
#include "AdjacencyList.hpp"
#include <vector>


class GeneticAlgorithm {
    private:
        int *costs;
        Vertex *list;
        Vertex *begin;
        Vertex *end;
        vector<Vertex *> path;
        double currentCost;
        int** population;
        int** new_population;
        int** descendants;
        int rowsP ; 
        int columnsP ;
        int sizeListVertex;
    public:
        GeneticAlgorithm(AdjacencyList* adjl);
        ~GeneticAlgorithm();
        double* fitness(); // Sempre será chamada para calcular os custos dos caminhos da population,  visto que a mesma será sempre alterada conforme ocorrer a seleção
        vector<Vertex *> lottery(vector<vector<Vertex*>> tracks);
        void selectInitialPopulation(int *array, int lenght, int avaliablePopulation);
        void selectAfterFit(int *vRows); // Irá retornar uma nova população
        int* insertionSort(double *vCosts);
        void crossover();
        void start();
        void free_newPopulation();
        void free_Population();
        void mutation();
};
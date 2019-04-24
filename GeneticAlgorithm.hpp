#pragma once
#include "AdjacencyList.hpp"
#include <vector>


class GeneticAlgorithm {
    private:
        int *costs;
        Vertex *list;
        Vertex *begin;
        Vertex *end;
        int ibegin; 
        int iend;
        vector<Vertex *> path;
        double currentCost;
        int** population;
        int** new_population;
        int** descendants;
        int* best_walk;
        int rowsP ; 
        int columnsP ;
        int sizeListVertex;
        //double* pointer_costs;
    public:
        GeneticAlgorithm(AdjacencyList* adjl);
        ~GeneticAlgorithm();
        double* fitness(int **population_matrix); // Sempre será chamada para calcular os custos dos caminhos da population,  visto que a mesma será sempre alterada conforme ocorrer a seleção
        vector<Vertex *> lottery(vector<vector<Vertex*>> tracks);
        void selectInitialPopulation(int *array, int lenght, int avaliablePopulation);
        void selectAfterFit(int *vRows); // Irá retornar uma nova população
        int* insertionSort(double *pointer_costs);
        void crossover(double *pointer_costs);
        void start();
        void free_newPopulation();
        void free_Population();
        void free_Descendants();
        void mutation();
        int roulette_weight(double *pointer_costs);
        void build_population(double *pointer_costs1,double *pointer_costs2);
};
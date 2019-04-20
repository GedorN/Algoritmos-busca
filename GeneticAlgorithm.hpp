#pragma once
#include "AdjacencyList.hpp"
#include <vector>


class GeneticAlgorithm {
    private:
        int *costs;
        vector<Vertex *> path;
    public:
        GeneticAlgorithm(AdjacencyList* adjl);
        ~GeneticAlgorithm();
        void fitness(vector<Vertex* > track);
        vector<Vertex *> lottery(vector<vector<Vertex*>> tracks);
        void selectInitialPopulation(int *array, int lenght, int avaliablePopulation);
};
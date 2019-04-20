#pragma once
#include "AdjacencyList.hpp"
#include <vector>


class GeneticAlgorithm {
    private:
        int *costs;
        Vertex *list;
        vector<Vertex *> path;
        double currentCost;
    public:
        GeneticAlgorithm(AdjacencyList* adjl);
        ~GeneticAlgorithm();
        void fitness(int *track, int lenght);
        vector<Vertex *> lottery(vector<vector<Vertex*>> tracks);
        void selectInitialPopulation(int *array, int lenght, int avaliablePopulation);
};
#include "GeneticAlgorithm.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

GeneticAlgorithm::GeneticAlgorithm(AdjacencyList* adjl) {
    Vertex *list = adjl->getList();
    int adslLenght = adjl->getLenght();
    int **population;
    population = (int **)malloc(sizeof(int *) * 20);
    for (int i = 0; i < adslLenght; i++) {
        population[i] = (int*) malloc (sizeof(int) * 10);
        selectInitialPopulation(population[i], 10, 100);
    }

    // =====================================
    //  PRINTING INITIAL POPULATION
    // =====================================
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%2d", population[i][j]);
        }
        putchar('\n');
    }




}


GeneticAlgorithm::~GeneticAlgorithm() {

}

void GeneticAlgorithm::fitness(vector<Vertex* > track) {

}

vector<Vertex *> GeneticAlgorithm::lottery(vector<vector<Vertex*>> tracks) {

}

void GeneticAlgorithm::selectInitialPopulation(int *array, int lenght, int avaliablePopulation) {
    srand(time(NULL));
    int i = 0;
    int j = 0;
    bool alreadyHas = false;
    while(i < lenght) {
        alreadyHas = false;
        int position = rand() % avaliablePopulation;
        for (j = 0; j < i; j++) {
            if(array[j] == position) {
                alreadyHas = true;
            }
            if (!alreadyHas) {
                array[i] = position;
                i++;
            }
        }
    }


}
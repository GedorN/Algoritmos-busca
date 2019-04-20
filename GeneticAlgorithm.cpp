#include "GeneticAlgorithm.hpp"
#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;

GeneticAlgorithm::GeneticAlgorithm(AdjacencyList* adjl) {
    list = adjl->getList();
    currentCost = 0;
    int adslLenght = adjl->getLenght();
    int **population;
    Vertex *begin, *end;
    population = (int **)malloc(sizeof(int *) * 20);
    for (int i = 0; i < 20; i++) {
        population[i] = (int*) malloc (sizeof(int) * 10);
        selectInitialPopulation(population[i], 10, 100);
    }

    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == '>') {
           begin = &list[i];
           break;
        }
    }
    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == 'x') {
            end = &list[i];
            break;
        }
    }
    begin->print();
    end->print();


    // =====================================
    //  PRINTING INITIAL POPULATION
    // =====================================
    // for (int i = 0; i < 20; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         printf("%5d", population[i][j]);
    //     }
    //     putchar('\n');
    // }

    //===================================================
    // DEFININDO CUSTOS DOS CAMINHOS
    // ================================================== 
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            list[population[i][j]].setGCost( abs(list[population[i][j]].getCoordinates()[0] - begin->getCoordinates()[0]) + abs(list[population[i][j]].getCoordinates()[1] - begin->getCoordinates()[1]));
            list[population[i][j]].setHCost( abs(list[population[i][j]].getCoordinates()[0] - end->getCoordinates()[0]) + abs(list[population[i][j]].getCoordinates()[1] - end->getCoordinates()[1]));
            list[population[i][j]].setFCost(list[population[i][j]].getGCost() + list[population[i][j]].getHCost());
        }
    }





    for (int i = 0; i < 20; i++) {
        free(population[i]);
    }
    free(population);




}


GeneticAlgorithm::~GeneticAlgorithm() {

}

void GeneticAlgorithm::fitness(int *track, int lenght) {
    double total = 0;
    for (int i = 0; i < lenght; i++) {
        total += list[track[i]].getFCost();
    }

}

vector<Vertex *> GeneticAlgorithm::lottery(vector<vector<Vertex*>> tracks) {

}

void GeneticAlgorithm::selectInitialPopulation(int *array, int lenght, int avaliablePopulation) {
    // srand(time_t(NULL));
    int i = 0;
    int j = 0;
    bool alreadyHas = false;
    while(i < lenght) {
        cout << "choosing population..." << endl;
        alreadyHas = false;
        int position = rand() % avaliablePopulation;
        for (j = 0; j < i; j++) {
            if(array[j] == position) {
                alreadyHas = true;
            }
        }
        if (!alreadyHas) {
            array[i] = position;
            i++;
        }
    }


}
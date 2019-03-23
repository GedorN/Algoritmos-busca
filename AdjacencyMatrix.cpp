#include "AdjacencyMatrix.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

AdjacencyMatrix::AdjacencyMatrix() {
    matrix = nullptr;
    rows = 0;
    columns = 0;
}

void AdjacencyMatrix::createByTxt(char* file) {
    FILE *maze = fopen(file, "r");
    if (maze == NULL) {
        cout<< "Arquivo não pode ser aberto!" << endl;
        exit(9);
    }
    fscanf(maze, "%d\n", &rows);
    fscanf(maze, "%d\n", &columns);

    matrix = (Vertex**)malloc(sizeof(Vertex*) * rows);
    for(int i = 0; i < columns; i++) {
        matrix[i] = (Vertex*)malloc(sizeof(Vertex) * columns);
    }

    printf("===============");
    putchar('\n');
    for(int i = 0; i< rows; i++) {
        for(int j = 0; j< columns; j++) {
            // if (fgetc(maze) ==  '.') {
            //     int aux[2] = {i, j};
            //     matrix[i][j].setCoordinates(aux);
            // } else {
            //     matrix[i][j].del();
            // }
            matrix[j][i] = new Vertex();
            putchar(fgetc(maze));
        }
        fscanf(maze, "\n");
        putchar('\n');
    }
    fclose(maze);
    printf(">>>>>>>>>>>>>>>>>>");
    putchar('\n');
}

void AdjacencyMatrix::print() {
    for(int i = 0; i< rows; i++) {
        for(int j = 0; j < columns; j++) {
            Coordinate a = matrix[i][j].getCoordinates();
            printf("(%i, %i)", a, j);
        }
        putchar('\n');
    }
}


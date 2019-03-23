#include "AdjacencyMatrix.hpp"
#include <iostream>
#include <stdio_ext.h>
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

    matrix = new Vertex*[rows];
    for(int i = 0; i < columns; i++) {
        matrix[i] = new Vertex[columns];
    }

    putchar('\n');
    for(int i = 0; i< rows; i++) {
        for(int j = 0; j< columns; j++) {
            if (fgetc(maze) ==  '.') {
                int aux[2] = {i, j};
                matrix[i][j].setCoordinates(aux);
                matrix[i][j].setPath();
            }
        }
        fscanf(maze, "\n");
    }
    fclose(maze);
}

void AdjacencyMatrix::print() {
    for(int i = 0; i< rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(matrix[i][j].isPath()) {
                int *a = matrix[i][j].getCoordinates();
                printf("(%d, %d)", a[0], a[1]);
            } else {
                printf("###"); 
            }
        }
        putchar('\n');
    }
}

void AdjacencyMatrix::freeMatrix() {
    for (int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}


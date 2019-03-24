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
            char c = fgetc(maze);
             int aux[2] = {i, j}; 
            if (c ==  '.') {
                matrix[i][j].setCoordinates(aux);
                matrix[i][j].setPath();
            } else if (c == '>') {
                matrix[i][j].setCoordinates(aux);
                matrix[i][j].setPath();
                begin[0] = aux[0];
                begin[1] = aux[1];
            } else if (c == 'x') {
                matrix[i][j].setCoordinates(aux);
                matrix[i][j].setPath();
                end[0] = aux[0];
                end[1] = aux[1];
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



Vertex* AdjacencyMatrix::northNeighbor(Coordinate* c) {
    Vertex a = matrix[c[0]][c[1] - 1];
}
Vertex* AdjacencyMatrix::northeastNeighbor(Coordinate* c) {

}
Vertex* AdjacencyMatrix::lestNeighbor(Coordinate* c) {

}
Vertex* AdjacencyMatrix::southeastNeighbor(Coordinate* c) {

}
Vertex* AdjacencyMatrix::southNeighbor(Coordinate* c) {

}
Vertex* AdjacencyMatrix::southWestNeighbor(Coordinate* c) {

}
Vertex* AdjacencyMatrix::westNeighbor(Coordinate* c) {

}
Vertex* AdjacencyMatrix::northwestNeighbor(Coordinate* c) {

}



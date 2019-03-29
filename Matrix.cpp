#include "Matrix.hpp"
#include <stdio.h>
#include <stdlib.h>

Matrix::Matrix(char* maze) {
    FILE *file = fopen(maze, "r");

    fscanf(file, "%d\n", &rows);
    fscanf(file, "%d\n", &columns);
    matrix = (char**)malloc(sizeof(char*) * rows);

    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(sizeof(char) * columns);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = fgetc(file);
        }
        fscanf(file, "\n");
    }

    fclose(file);
}

Matrix::~Matrix() {
    printf("Destruindo Matrix \n");
    for (int i = 0; i < rows; i ++) {
        free(matrix[i]);
    }
    free(matrix);
}

char** Matrix::getMatrix() {
    return matrix;
}

int Matrix::getColumns() {
    return columns;
}

int Matrix::getRows() {
    return rows;    
}

void Matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%2c", matrix[i][j]);
        }
        putchar('\n');
    }
}
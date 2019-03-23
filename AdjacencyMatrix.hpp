#pragma once
#include "Vertex.hpp"
class AdjacencyMatrix {
    private:
        Vertex** matrix;
        int rows;
        int columns; 
    public:
        AdjacencyMatrix();
        void createByTxt(char* file);
        void print();
        void freeMatrix();
};
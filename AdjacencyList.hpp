#pragma once
#include "Matrix.hpp"
#include "List.hpp"
#include "Vertex.hpp"
#include <stdio_ext.h>
#include <stdlib.h>

class AdjacencyList {
    private:
        Vertex* vertexList;
        int lenght;
    public:
        AdjacencyList(Matrix* matrixObj);
        ~AdjacencyList();
        Vertex* getList();
        int getLenght();
        void print();
};
#pragma once
#include "Matrix.hpp"
#include "List.hpp"
#include <stdio_ext.h>
#include <stdlib.h>
class AdjacencyList {
    private:
    List* list;
    int lenght;
    public:
    AdjacencyList(Matrix* matrixObj);
    ~AdjacencyList();
    List* getList();
    void print();
};
#pragma once
#include "Vertex.hpp"
class AdjacencyMatrix {
    private:
        Vertex** matrix;
        int rows;
        int columns;
        Coordinate begin[2];
        Coordinate end[2];
    public:
        AdjacencyMatrix();
        void createByTxt(char* file);
        void print();
        Coordinate* getBegin();
        Coordinate* getEnd();
        Vertex* northNeighbor(Coordinate* c);
        Vertex* northeastNeighbor(Coordinate* c);
        Vertex* lestNeighbor(Coordinate* c);
        Vertex* southeastNeighbor(Coordinate* c);
        Vertex* southNeighbor(Coordinate* c);
        Vertex* southWestNeighbor(Coordinate* c);
        Vertex* westNeighbor(Coordinate* c);
        Vertex* northwestNeighbor(Coordinate* c);
        void freeMatrix();
};
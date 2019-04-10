#pragma once
#include "AdjacencyList.hpp"
#include <list>

class AStar {
    private:
        list<Vertex*> path;
    public:
        AStar(AdjacencyList* adjl);
        ~AStar();
};
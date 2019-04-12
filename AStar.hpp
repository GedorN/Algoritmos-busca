#pragma once
#include "AdjacencyList.hpp"
#include <list>

class AStar {
    private:
        list<Vertex*> path;
    public:
        AStar(AdjacencyList* adjl);
        ~AStar();
        bool isOnList(list<Vertex*> list, Vertex *element);
        void sort(list<Vertex*> *list);
};
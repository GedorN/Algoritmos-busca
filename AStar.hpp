#pragma once
#include "AdjacencyList.hpp"
#include <list>
#include <vector>

class AStar {
    private:
        list<Vertex*> path;
    public:
        AStar(AdjacencyList* adjl);
        ~AStar();
        bool isOnList(vector<Vertex*> list, Vertex *element);
        void sort(vector<Vertex*> *list);
        void printList(vector<Vertex *> list);
        void tracePath(Vertex* vertex);
        void printPath();
};
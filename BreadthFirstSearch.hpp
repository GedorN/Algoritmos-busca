#pragma once
#include<list>
#include "AdjacencyList.hpp"
class BreadthFirstSearch {
    private:
        list<Vertex*> path;
    public:
        BreadthFirstSearch(AdjacencyList* adsl);
        ~BreadthFirstSearch();
        void tracePath(Vertex* vertex);
        void printPath();
        list<Vertex*> getPath();
};
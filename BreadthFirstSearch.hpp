#pragma once
#include<list>
#include "AdjacencyList.hpp"
class BreadthFirstSearch {
    private:
        list<Vertex*> path;
    public:
        BreadthFirstSearch(AdjacencyList* adsl);
        ~BreadthFirstSearch();
};
#pragma once
#include"Vertex.hpp"
#include<iostream>
using namespace std;
typedef int Coordinate;
/*o char pode ser necessário ou não... não sei ainda*/
class List {
    private:
        // char spot;
        Vertex* vertex;
        List* next;
    public:
        List();
        List(Vertex* v);
        List* insert(Vertex *v);
        int listSize();
        void print();
        void remove(Coordinate sport);
        void destroyAll(List* list);
};

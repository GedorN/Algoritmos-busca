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
        ~List();
        List(Vertex* v);
        List* insert(Vertex *v);
        Vertex* getNode(int index);
        Vertex* getNode(Coordinate *index);
        int listSize();
        int lenght();
        void print();
        void remove(Coordinate sport);
        void destroyAll(List* list);
};

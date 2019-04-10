#include "AStar.hpp"
#include <iostream>
using namespace std;

AStar::AStar(AdjacencyList* adjl) {
    list<Vertex *> closedList;
    list<Vertex *> openList;
    Vertex* list = adjl->getList();

    // list[0].print();

    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == '>') {
            list[i].setFather(nullptr);
            closedList.push_back(&list[i]);
            break;
        }
    }

    closedList.front()->print();



}

AStar::~AStar() {

}
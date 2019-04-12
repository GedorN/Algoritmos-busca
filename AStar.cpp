#include "AStar.hpp"
#include <iostream>
using namespace std;

AStar::AStar(AdjacencyList* adjl) {
    list<Vertex *> closedList;
    list<Vertex *> openList;
    Vertex* list = adjl->getList();
    Vertex * aux = nullptr;


    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == '>') {
            list[i].setFather(nullptr);
            openList.push_back(&list[i]);
            break;
        }
    }
    openList.front()->print();

    while(openList.size() > 0) {
        aux= openList.front();
        for(int i = 0; i < aux->getNeighborhoodsNumber(); i++) {
            if(!isOnList(closedList, aux)) {
                openList.push_back( &list[aux->getNeighborhood(i) ] );
            }
        }

        openList.pop_front();
    }
    



}

AStar::~AStar() {

}

bool AStar::isOnList(list<Vertex*> list, Vertex *element) {
    std::list<Vertex*>::iterator i;
    for(i = list.begin(); i != list.end(); i++) {
        if(element->getCoordinates()[0] == (*i)->getCoordinates()[0] && element->getCoordinates()[1] == (*i)->getCoordinates()[1])
        return true;
    }

    return false;
}

void AStar::sort(list<Vertex*> *list) {
    std::list<Vertex *>::iterator i = list->begin()++;
    Vertex *key = nullptr;
    std::list<Vertex *>::iterator j = i;    
    j--;
        
    for (i; i != list->end(); i++) {
        key = (*i);
        while(j)
    }
}
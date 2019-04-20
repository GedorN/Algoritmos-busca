#include "BreadthFirstSearch.hpp"
#include<iostream>
#include <list>
using namespace std;
BreadthFirstSearch::BreadthFirstSearch(AdjacencyList *adjl) {
    cout<< "Construtora da BFS"<< endl;
    list<Vertex*> queue;
    Vertex *aux= nullptr;
    list<Vertex *> path;
    Vertex* list = adjl->getList();
    int lIndex= 0;
    int distance = 0;
    Vertex *v = nullptr;
    // Vertex* pFather = nullptr;


    for (int lIndex = 0; lIndex < adjl->getLenght(); lIndex++)  {
        if(list[lIndex].getContent() == '>') {
            list[lIndex].setColor(GREY);
            list[lIndex].setDistance(0);
            list[lIndex].setFather(nullptr);
            queue.push_back(&list[lIndex]);
            break;
        }
    }
    // cout<< aux->print()<<endl;
    cout << "============= inicio ================="<< endl;


    while(queue.size() > 0) {

        aux = queue.front();
        queue.pop_front();
        for (int i = 0; i < aux->getNeighborhoodsNumber(); i++) {
            // cout<< "COLOR: "<< list[list[lIndex].getNeighborhood(i)].getColor() <<endl;
           
            if (list[aux->getNeighborhood(i)].getColor() == WHITE) {

                list[aux->getNeighborhood(i)].setFather(aux);
                list[aux->getNeighborhood(i)].setColor(GREY);

                queue.push_back(&list[aux->getNeighborhood(i)]);
            }
        }
        aux->setColor(BLACK);
        if (aux->getContent() == 'x') {
           tracePath(aux);
        }
    // v= nullptr;

    }
    // cout<< "Queue size: " << queue.size() << endl;
}

BreadthFirstSearch::~BreadthFirstSearch() {

}

list<Vertex*> BreadthFirstSearch::getPath() {
    return path;
}

void BreadthFirstSearch::tracePath(Vertex* vertex) {
    Vertex *backTrack = vertex;
    while(backTrack != nullptr) {
        path.push_front(backTrack);
        backTrack= backTrack->getFather();
    }
}

void BreadthFirstSearch::printPath() {
    cout << "============ CAMINHO ===========================" <<endl;
    std::list<Vertex *>::iterator alpha;
    for(alpha = path.begin(); alpha != path.end(); alpha++ ){
       cout << "(" << (*alpha)->getCoordinates()[0] << ", " << (*alpha)->getCoordinates()[1] << ")" <<endl;
        // (*alpha)->print();
    }
}
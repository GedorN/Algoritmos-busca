#include "AStar.hpp"
#include <iostream>
#include<math.h>
#include <vector>
#include <algorithm>
using namespace std;

AStar::AStar(AdjacencyList* adjl) {
    vector<Vertex *> closedList;
    vector<Vertex *> openList;
    Vertex *end = nullptr;
    Vertex* list = adjl->getList();
    Vertex * aux = nullptr;


    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == '>') {
            list[i].setFather(nullptr);
            openList.push_back(&list[i]);
            break;
        }
    }

    for(int i = 0; i < adjl->getLenght(); i++) {
        if(list[i].getContent() == 'x') {
            list[i].setFather(nullptr);
            end = &list[i];
            break;
        }
    }
    openList[0]->print();
    end->print();
    // getchar();
    while(openList.size() > 0) {
        aux= openList.front();
        cout<< "WHO IS IN FRONT?"<<endl;
        aux->print();
        // getchar();

        if(aux->getContent() == 'x' ) {
            cout<< "ACHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOU========================"<< endl;
            aux->print();
            tracePath(aux);
            printPath();
            // getchar();
            break;
        }
        for(int i = 0; i < aux->getNeighborhoodsNumber(); i++) {
            Vertex *neighborhood = &list[aux->getNeighborhood(i)];
            /* Se o nó ainda não tiver sido inserido na lista aberta*/
            if(!isOnList(closedList, neighborhood)) {
                if(!isOnList(openList, neighborhood)) {
                    neighborhood->setFather(aux);
                    if(neighborhood->getCoordinates()[0] != aux->getCoordinates()[0] && neighborhood->getCoordinates()[1] != aux->getCoordinates()[1]) {
                        neighborhood->setGCost(neighborhood->getGCost() + 14);
                    } else {
                        neighborhood->setGCost(neighborhood->getGCost() + 10);
                    }

                    neighborhood->setHCost( (abs(neighborhood->getCoordinates()[0] - end->getCoordinates()[0]) + abs(neighborhood->getCoordinates()[1] - end->getCoordinates()[1])) * 10 );
                    neighborhood->setFCost(neighborhood->getGCost() + neighborhood->getHCost());
                    openList.push_back( &list[aux->getNeighborhood(i) ] );

                } else { /*Caso o nó ja tenha sido inserido na lista aberta*/
                    double f = 0, g = 0;
                    g = aux->getGCost();
                    if(neighborhood->getCoordinates()[0] != aux->getCoordinates()[0] && neighborhood->getCoordinates()[1] != aux->getCoordinates()[1]) {
                        g += 14;
                    } else {
                        g += 10;
                    }
                    if(g < neighborhood->getGCost()) {
                        neighborhood->setGCost(g);
                        neighborhood->setFCost(neighborhood->getGCost() + neighborhood->getHCost());
                        neighborhood->setFather(aux);
                    }
                }
            } else {
                cout << "Esse já ta na lista" << endl;
                neighborhood->print();
                // getchar();
            }
        }
        closedList.push_back(openList.front());
        openList.erase(openList.begin());
        std::sort(openList.begin(), openList.end(), [](Vertex* a, Vertex* b) {
            return a->getFCost() < b->getFCost();
        });
        printList(openList);
    }
    
}

AStar::~AStar() {

}

bool AStar::isOnList(vector<Vertex*> list, Vertex *element) {
    std::vector<Vertex*>::iterator i;
    for(i = list.begin(); i != list.end(); i++) {
        if(element->getCoordinates()[0] == (*i)->getCoordinates()[0] && element->getCoordinates()[1] == (*i)->getCoordinates()[1])
        return true;
    }

    // for(int i = 0; i < list.size(); i++) {
    //     if(element->getCoordinates()[0] == list[i]->getCoordinates()[0] && element->getCoordinates()[1] == list[i]->getCoordinates()[1]) {
    //         return true;
    //     }
    // }

    return false;
}

// void AStar::sort(list<Vertex*> *list) {
//     std::list<Vertex *>::iterator i = list->begin()++;
//     Vertex *key = nullptr;
//     std::list<Vertex *>::iterator j = i;    
//     j--;
        
//     for (i; i != list->end(); i++) {
//         key = (*i);
//         while(j != )
//     }
// }


void AStar::printList(vector<Vertex *> list) {
    for (int i = 0; i < list.size(); i++) {
        list[i]->print();
        // getchar();
    }
}

void AStar::tracePath(Vertex* vertex) {
    Vertex* aux = vertex;
    while(aux != nullptr) {
        path.push_front(aux);
        aux = aux->getFather();
    }
}

void AStar::printPath() {
    cout << "============ CAMINHO ===========================" <<endl;
    std::list<Vertex *>::iterator i;
    for (i = path.begin(); i != path.end(); i++) {
        cout << "("<< (*i)->getCoordinates()[0] << ", " << (*i)->getCoordinates()[1] << ")" << endl;
    }
    // for (int i = 0; i < path.size(); i++) {
    // }
}

list<Vertex*> AStar::getPath() {
    return path;
}
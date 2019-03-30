#include "BreadthFirstSearch.hpp"
#include<iostream>
using namespace std;
BreadthFirstSearch::BreadthFirstSearch(AdjacencyList *adjl) {
    cout<< "Construtora da BFS"<< endl;
    list<Vertex *> queue;
    List* list = adjl->getList();
    int lIndex= 0;
    Vertex *v = nullptr;

    // adjl->print();

    for (int lIndex = 0; lIndex < adjl->getLenght(); lIndex++)  {
        v = list[lIndex].getNode('>');
        if(v != nullptr) {
            v->setColor(GREY);
            v->setDistance(0);
            v->setFather(nullptr);
            queue.push_back(v);
            break;
        }
    }
  
    cout << "============= INICIO ============" <<endl;
    cout << "("<< v->getCoordinates()[0] << ", " << v->getCoordinates()[1]<< ")" << endl;
    cout << "==========" << endl;
    // v = queue.front();
    // queue.push_back(list[0].getNode(0));
    // a = v->getCoordinates();
    // cout<< "(" << a[0] << ", "<< a[1]<< ")" << endl;
    while(queue.size() > 0) {
        cout<< "Queue size: " << queue.size() << endl;
        // cout<< "Lengh? " << adjl->getLenght()<< endl;
        Vertex* head = queue.front();
        queue.pop_front();

        for (lIndex = 0; lIndex < adjl->getLenght(); lIndex++) {
            v = list[lIndex].getNode(0);
            cout << "("<< v->getCoordinates()[0] << ", " << v->getCoordinates()[1]<< ")" << endl;
            cout << "("<< head->getCoordinates()[0] << ", " << head->getCoordinates()[1]<< ")" << endl;
            if(v->getCoordinates()[0] == head->getCoordinates()[0] && v->getCoordinates()[1] == head->getCoordinates()[1]) {
                cout << "("<< v->getCoordinates()[0] << ", " << v->getCoordinates()[1]<< ")" << endl;
                cout << "("<< head->getCoordinates()[0] << ", " << head->getCoordinates()[1]<< ")" << endl;
                break;
            }   
        }

        for (int i = 1; i < list[lIndex].lenght(); i++) {
            Vertex *aux = list[lIndex].getNode(i);
            if (aux->getColor() == WHITE) {
                cout<< "Vertex: " << aux->getContent()<< "   ";
                cout << "("<< aux->getCoordinates()[0] << ", " << aux->getCoordinates()[1]<< ")" << endl;
                aux->setColor(GREY);
                aux->setDistance(aux->getDistance() + 1);
                aux->setFather(v);
                if(aux->getContent() == 'x') {
                    Vertex * father = aux;;
                    cout<< "============= PATH =============="<<endl;
                    while(father != nullptr) {
                        cout << "("<< father->getCoordinates()[0] << ", " << father->getCoordinates()[1]<< ")" << endl;
                    }
                    cout<< "==================================" <<endl;
                    break;
                }
                queue.push_back(aux);
            }
            if(aux->getContent() == 'x') {
                cout<< "BREAK"<< endl;
                break;
            }
        }
        list[lIndex].getNode(0)->setColor(BLACK);
        v= nullptr;

    }
    cout<< "Queue size: " << queue.size() << endl;
    cout<< "(" << v->getCoordinates()[0] << ", "<< v->getCoordinates()[1]<< ")" << endl;
}

BreadthFirstSearch::~BreadthFirstSearch() {

}
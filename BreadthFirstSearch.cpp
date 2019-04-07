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

    list[0].print();

    for (int lIndex = 0; lIndex < adjl->getLenght(); lIndex++)  {
        if(list[lIndex].getContent() == '>') {
            list[lIndex].setColor(GREY);
            list[lIndex].setDistance(0);
            list[lIndex].setFather(nullptr);
            queue.push_back(&list[lIndex]);
            break;
        }
    }
    queue.front()->print();
    // cout<< aux->print()<<endl;
    cout << "============= inicio ================="<< endl;


    while(queue.size() > 0) {
        cout<< "Queue size: " << queue.size() << endl;
        // Vertex* head = queue.front();
        

        // Vertex *pFather = v;
        // for (lIndex = 0; lIndex < adjl->getLenght(); lIndex++) {
        //     v = list[lIndex].getNode(0);
        //     cout << "("<< v->getCoordinates()[0] << ", " << v->getCoordinates()[1]<< ")" << " = ";
        //     cout << "("<< head->getCoordinates()[0] << ", " << head->getCoordinates()[1]<< ")" << endl;
        //     if(v->getCoordinates()[0] == head->getCoordinates()[0] && v->getCoordinates()[1] == head->getCoordinates()[1]) {
        //             // v->setFather(pFather);
        //             // pFather = v;
        //         if(v->getContent() == 'x') {
        //             Vertex *father = v;

        //             for(int j = 0; j < adjl->getLenght(); j++) {
        //                 if (father->getCoordinates()[0] == list[j].getNode(0)->getCoordinates()[0] && father->getCoordinates()[1] == list[j].getNode(0)->getCoordinates()[1]) {
        //                     father = list[j].getNode(0);
        //                 }

        //             }
        //             cout<< "============= achooou =============="<<endl;
        //             getchar();
        //             while(father->getContent() != '>') {
        //                 cout<< "============= PATH =============="<<endl;
        //                 cout << "("<< father->getCoordinates()[0] << ", " << father->getCoordinates()[1]<< ")" << endl;
        //                 getchar();
        //                 path.push_front(father);

        //                 father = father->getFather();
        //                 for(int j = 0; j < adjl->getLenght(); j++) {
        //                     if (father->getCoordinates()[0] == list[j].getNode(0)->getCoordinates()[0] && father->getCoordinates()[1] == list[j].getNode(0)->getCoordinates()[1]) {
        //                         father = list[j].getNode(0);
        //                     }

        //                 }
        //             }
        //             cout<< "==================================" <<endl;
        //             cout<< "============= VAI BRECA =============="<<endl;
        //             getchar();
        //             break;
        //             }


        //         break;
        //     }   
        // }

        // v->print();
        // getchar();
            // distance++;
        aux = queue.front();
        queue.pop_front();
        for (int i = 0; i < aux->getNeighborhoodsNumber(); i++) {
            // cout<< "COLOR: "<< list[list[lIndex].getNeighborhood(i)].getColor() <<endl;
           
            if (list[aux->getNeighborhood(i)].getColor() == WHITE) {

                list[aux->getNeighborhood(i)].setFather(aux);
                list[aux->getNeighborhood(i)].setColor(GREY);
              
                cout<< "================== ELE====================== "<<endl;
                list[aux->getNeighborhood(i)].print();
                cout<< "=================PAI DELE ===================="<<endl;
                list[aux->getNeighborhood(i)].getFather()->print();


                queue.push_back(&list[aux->getNeighborhood(i)]);
            }
        }
        aux->setColor(BLACK);
        if (aux->getContent() == 'x') {
            Vertex *backTrack = aux;
            while(backTrack != nullptr) {
                path.push_back(backTrack);
                backTrack= backTrack->getFather();
            }
        }
    // v= nullptr;

    }
    // cout<< "Queue size: " << queue.size() << endl;
   cout << "DESEJA VER O FIM DO CAMINHO? "<<endl;
   getchar();
   std::list<Vertex *>::iterator alpha;
   for(alpha = path.begin(); alpha != path.end(); alpha++ ){
       cout << "(" << (*alpha)->getCoordinates()[0] << ", " << (*alpha)->getCoordinates()[1] << ")" <<endl;
    // (*alpha)->print();
   }
   getchar();
}

BreadthFirstSearch::~BreadthFirstSearch() {

}
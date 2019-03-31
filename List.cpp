#include"List.hpp"
#include<iostream>
using namespace std;

List::List()
{
    vertex = nullptr;
    next = nullptr;
}



List::~List() {
    cout<< "Destruindo List" << endl;
    List* walker = this;
    List* aux = walker;
    while(aux != nullptr) {
        walker = aux->next;
        free(aux->vertex);
        aux = walker;
    }
}

List::List(Vertex* v)
{ 
    vertex = v; 
    next = nullptr;
} 

void List::insert(Vertex* v)
{ 
    List *aux = this;
    if (aux->vertex == nullptr) {
        cout<< "Novo cara========="<<endl;
        vertex = v;
        next = nullptr;
        // return created;
    } else {
        List *created = new List(v);
        while(aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = created;
    }

    // return this;
}

void List::print()
{
    List *aux = this;
    if(vertex == nullptr) {
        exit(9);
    }
    while(aux != nullptr) {
        cout << "(" << aux->vertex->getCoordinates()[0] << ", " << aux->vertex->getCoordinates()[1] << ")";
        aux = aux->next;
    }
    cout << endl;
}

void List::destroyAll(List* list)
{
    // List *aux = list;
    // List *i = aux;
    // if(this == nullptr) {
    //     exit(9);
    // }

    // while(i != NULL) {
    //     cout << "deleting..." << aux->x << " " << aux->y << endl;
    //     i = i->next;
    //     delete(aux);
    //     aux = i;
    // }
}

int List::listSize() 
{
    int total = 0;   
    List* aux = this;
    while (aux != NULL) {
        total+= sizeof(aux); 
        aux = aux -> next;
    }

    return total;
}

Vertex* List::getNode(int index) {
    List* aux = this;
    for(int i = 0 ; i < index; i++) {
        if (aux == nullptr) {
            cout<< "Segmentation fault: no index" << endl;
            exit(-1);
        }
        aux = aux->next;
    }
    return aux->vertex;
}

Vertex* List::getNode(Coordinate *index) {
    List* aux = this;
    for (int i = 0; i < lenght(); i++) {
        if (aux == nullptr) {
            cout<< "Segmentation fault: no cooridnate" << endl;
            exit(-1);
        }
        Coordinate *coord = aux->vertex->getCoordinates();
        if(coord[0] == index[0] && coord[1] == index[1]) {
            return aux->vertex;
        }
        aux = aux->next;

    }
    return nullptr;
}

Vertex* List::getNode(char content) {
    List* aux = this;
    for (int i = 0; i < lenght(); i++) {
        if (aux == nullptr) {
            cout<< "Segmentation fault: no cooridnate" << endl;
            exit(-1);
        }
        if(aux->vertex->getContent() == content) {
            return aux->vertex;
        }
        aux = aux->next;

    }
    return nullptr;
}

int List::lenght() {
    int total = 0;
    List *aux = this;
    while(aux != NULL) {
        total++;
        aux = aux->next;
    }

    return total;
}
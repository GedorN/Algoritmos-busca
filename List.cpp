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

List* List::insert(Vertex* v)
{ 
    List *created = new List(v);
    List *aux = this;
    if (aux->vertex == nullptr) {
        return created;
    }
    while(aux->next != nullptr) {
        aux = aux->next;
    }
    aux->next = created;

    return this;
}

void List::print()
{
    List *aux = this;
    if(vertex == nullptr) {
        cout<<"cheguei aqui" << endl;
        exit(9);
    }
    do {
        int *a = aux->vertex->getCoordinates();
        cout << "(" << a[0] << ", " << a[1] << ")";
        aux = aux->next;

    } while (aux != nullptr);
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
    return NULL;
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
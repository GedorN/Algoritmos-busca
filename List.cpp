#include"List.hpp"

#include<iostream>
using namespace std;

List::List()
{
    x = NULL;
    y = NULL;
    next = nullptr;
}

List::List(Coordinate x0, Coordinate y0)
{
    x = x0;
    y = y0; 
    next = nullptr;
} 

List* List::insert(Coordinate x, Coordinate y)
{
    List *created = new List(x, y);
    List *aux = this; 
    while(aux->next != nullptr) {
        aux = aux->next;
    }
    aux->next = created;

    return this;
}

void List::print()
{
    List *aux = this;
    if(x == NULL || y == NULL) {
        exit(9);
    }
    do {
        cout << "(" << aux->x << ", " << aux->y << ")";
        aux = aux->next;

    } while (aux != nullptr);
    cout << endl;
}

void List::destroyAll(List* list)
{
    List *aux = list;
    List *i = aux;
    if(this == nullptr) {
        exit(9);
    }

    while(i != NULL) {
        cout << "deleting..." << aux->x << " " << aux->y << endl;
        i = i->next;
        delete(aux);
        aux = i;
    }
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
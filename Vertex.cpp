#include "Vertex.hpp"
#include <iostream>
using namespace std;
Vertex::Vertex() {
    coordinates[0] = NULL;
    coordinates[1] = NULL;
    f = g = h = 0;
    distance = 0;
    p = nullptr;
    color = WHITE;
    content = NULL;
}

Vertex::~Vertex() {
    cout <<"dying"<<endl;
}

void Vertex::setCoordinates(int *c) {
    coordinates[0] = c[0];
    coordinates[1] = c[1];
}

void Vertex::setCoordinates(int x, int y) {
    // cout<< "Adicionando coordenadas: " << x << " " << y<< endl;
    coordinates[0] = x;
    coordinates[1] = y;
}

void Vertex::setColor(char c) {
    cout<< "Setting color for " << c << endl;
    color = c;
}

void Vertex::setFather(Vertex* father) {
    p = father;
}
void Vertex::setDistance(int d) {
    distance = d;
}

Coordinate* Vertex::getCoordinates() {
    return coordinates;
}

Vertex* Vertex::getFather() {
    return p;
}

int Vertex::getDistance() {
    return distance;
}


void Vertex::del() {
    delete this;
}

void Vertex::setContent(char c) {
    content = c;
}

char Vertex::getContent() {
    return content;
}

char Vertex::getColor() {
    return color;
}

void Vertex::printCoords() {
    cout << "(" << coordinates[0] << ", " << coordinates[1] << ") ";
}

void Vertex::print() {
    cout << "PAI: ";
    if(p != nullptr) {
        p->printCoords();
        cout<<endl;
    } else {
        cout << "null" << endl; ;
    }
    cout<< "Coordenadas: ";
    printCoords();
    cout<<endl;
    
    cout<< "CONTEUDO: " << content << endl;

    cout<<"COR: " << color;

    cout<< " >> ";
    list<int>::iterator it;
    for(it = neighborhoods.begin(); it != neighborhoods.end(); it++) {
        cout<< *it << " ";
    }

    cout << endl << endl;
}

void Vertex::setNeighborhood(int neighborhood) {
    neighborhoods.push_back(neighborhood);
}

void Vertex::getNeighborhoods(list<int> &out) {
    list<int>::iterator i;
    for(i = neighborhoods.begin(); i != neighborhoods.end(); i++) {
        out.push_back(*i);
    }
}

int Vertex::getNeighborhoodsNumber() {
    cout<< "Vizinhos: " << neighborhoods.size() << endl;
    return neighborhoods.size();
}

int Vertex::getNeighborhood(int index) {
    list<int>::iterator it;
    int i = 0;
    for(it = neighborhoods.begin(), i = 0; it != neighborhoods.end(); i++, it++) {
        if(i == index) {
            cout << "Returning: " << *it <<endl;
            return *it;
        }
    }
    //  printf("NOBODY==================================");
    return NULL;
}
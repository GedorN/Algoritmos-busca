#include "Vertex.hpp"
#include <iostream>
using namespace std;
Vertex::Vertex() {
    coordinates[0] = NULL;
    coordinates[1] = NULL;
    distance = 0;
    p = nullptr;
    color = WHITE;
    content = NULL;
}

Vertex::~Vertex() {
    
}

void Vertex::setCoordinates(int *c) {
    coordinates[0] = c[0];
    coordinates[1] = c[1];
}

void Vertex::setCoordinates(int x, int y) {
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

void Vertex::print() {
    cout<< "Coordinates: (" << coordinates[0] << ", " << coordinates[1]<< ")" << endl;
    cout<< "Distance: " << distance << endl;
    cout<< "Color: " << color << endl;
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
#include "Vertex.hpp"
#include <iostream>
using namespace std;
Vertex::Vertex() {
    coordinates[0] = 2;
    coordinates[1] = 5;
    distance = 0;
    p = nullptr;
    color = WHITE;
}

void Vertex::setCoordinates(int *c) {
    coordinates[0] = c[0];
    coordinates[1] = c[1];
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

Coordinate Vertex::getCoordinates() {
    return coordinates[0];
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
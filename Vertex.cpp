#include "Vertex.hpp"
#include <iostream>
using namespace std;
Vertex::Vertex(Coordinate *xy) {
    coordinates[0] = xy[0];
    coordinates[1] = xy[1];
    distance = 0;
    p = nullptr;
    color = WHITE;
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
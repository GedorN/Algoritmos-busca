#pragma once
#define WHITE 'W'
#define GREY 'G'
#define BLACK 'B'

typedef int Coordinate;
class Vertex {
    private:
        Coordinate coordinates[2];
        char color;
        int distance;
        Vertex *p;
    public:
    Vertex(Coordinate *xy);
    void setColor(char color);
    void setFather(Vertex* p);
    void setDistance(int d);
    Coordinate* getCoordinates();
    Vertex* getFather();
    int getDistance();
    void print();
};
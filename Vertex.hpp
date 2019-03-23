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
        bool path;
    public:
    Vertex();
    void setColor(char color);
    void setFather(Vertex* p);
    void setDistance(int d);
    void setCoordinates(int *c);
    Coordinate* getCoordinates();
    void setPath();
    bool isPath();
    Vertex* getFather();
    int getDistance();
    void print();
    void del();
};
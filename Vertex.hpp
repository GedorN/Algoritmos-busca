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
        char content;
        Vertex *p;
    public:
    Vertex();
    ~Vertex();
    void setColor(char color);
    void setFather(Vertex* p);
    void setDistance(int d);
    void setCoordinates(int *c);
    void setCoordinates(int x, int y);
    void setContent(char c);
    char getContent();
    Coordinate* getCoordinates();
    Vertex* getFather();
    int getDistance();
    char getColor();
    void print();
    void del();
};
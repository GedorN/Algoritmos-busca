#pragma once
#include <list>
#include<iostream>
#define WHITE 'W'
#define GREY 'G'
#define BLACK 'B'
using namespace std;
typedef int Coordinate;
class Vertex {
    private:
        Coordinate coordinates[2];
        char color;
        int distance;
        char content;
        double f;
        double g;
        double h;
        list<int> neighborhoods;
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
    void setNeighborhood(int neighborhood);
    void setFCost(double nf);
    void setGCost(double ng);
    void setHCost(double nh);
    char getContent();
    double getFCost();
    double getGCost();
    double getHCost();
    Coordinate* getCoordinates();
    Vertex* getFather();
    int getDistance();
    char getColor();
    int getNeighborhoodsNumber();
    int getNeighborhood(int index);
    void getNeighborhoods(list<int> &out);
    void del();
    void printCoords();
    void print();

};
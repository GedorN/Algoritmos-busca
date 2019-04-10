#include "List.hpp"
#include"AdjacencyList.hpp"
#include "Matrix.hpp"
#include "BreadthFirstSearch.hpp"
#include "AStar.hpp"
#include<stdlib.h>
#include <stdio_ext.h>
#include<iostream>
#include<list>
using namespace std;


int main ()
{   
    // AdjacencyMatrix *ad = new AdjacencyMatrix();
    // ad->createByTxt("Env.txt");
    // ad->freeMatrix();
    // ad->print();
    // Vertex *v = new Vertex();
    // v->print();
    Matrix matrix("Env.txt");
    matrix.print();
    AdjacencyList adjl(&matrix);
    // adjl.print();
    // BreadthFirstSearch bfs(&adjl);
    AStar as(&adjl);
}

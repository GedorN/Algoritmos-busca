#include "List.hpp"
#include"AdjacencyList.hpp"
#include "Matrix.hpp"
#include "BreadthFirstSearch.hpp"
#include "GeneticAlgorithm.hpp"
#include "AStar.hpp"
#include "Animation.hpp"
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
    Animation a(&matrix);
    // Robot a;
    // a.execute(as.getPath());
    // a->execute();
    // robot.execute();
    
    // GeneticAlgorithm ga(&adjl);
    // GeneticAlgorithm ga(&adjl);

}


// void execute(list<Vertex *> path) {
//         printf("\n entered....\n");
//         std::list<Vertex *>::iterator i;
//         for (i = path.begin(); i != path.end(); i++) {
//             setLocation((*i)->getCoordinates()[0], (*i)->getCoordinates()[1]);
//             print_state();
//             usleep(1000000);

//         }
// }
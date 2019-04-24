#include "List.hpp"
#include"AdjacencyList.hpp"
#include "Matrix.hpp"
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

int kbhit(void);
int main ()
{   
    // AdjacencyMatrix *ad = new AdjacencyMatrix();
    // ad->createByTxt("Env.txt");
    // ad->freeMatrix();
    // ad->print();
    // Vertex *v = new Vertex();
    // v->print();
    Matrix matrix("Env.txt");
    //matrix.print();
    AdjacencyList adjl(&matrix);
    AdjacencyList* aux;
    aux = &adjl;
    GeneticAlgorithm ga(aux);
        char input = '0';
    system("clear");
    printf("BEM VINDO A BUSCAS INTELIGENTES: \n");
    printf("Insira o número correspondente da busca desejada \n");
    printf("(1) - Busca em largura \n");
    printf("(2) - Busca A* \n");
    while(input != 'q') {
        input = kbhit();
        if (input != 0) {
            input = getchar();
            if(input == '1') {
                BreadthFirstSearch bfs(&adjl);
                Animation a(&matrix, bfs.getPath());
            } else if (input == '2') {
                AStar as(&adjl);
                Animation a(&matrix, as.getPath());
            }
        system("clear");
        printf("BEM VINDO A BUSCAS INTELIGENTES: \n");
        printf("Insira o número correspondente da busca desejada \n");
        printf("(1) - Busca em largura \n");
        printf("(2) - Busca A* \n");
        }

    }


    // adjl.print();
    
    // bfs.printPath();

    // as.printPath();
    // getchar();

    // Robot a;
    // a.execute(as.getPath());
    // a->execute();
    // robot.execute();
    
    // GeneticAlgorithm ga(&adjl);
    // GeneticAlgorithm ga(&adjl);
  
}
int kbhit(void)
    {
      struct termios oldt, newt;
      int ch;
      int oldf;
     
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
      fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
     
      ch = getchar();
     
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      fcntl(STDIN_FILENO, F_SETFL, oldf);
     
      if(ch != EOF)
      {
        ungetc(ch, stdin);
        return 1;
      }
     
      return 0;
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
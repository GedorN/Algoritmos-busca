#include <unistd.h>
#include <iostream>
#include "Animation.hpp"

Animation::Animation(Matrix *m, list<Vertex*> path) {
    matrix = m->getMatrix();
    rows = m->getRows();
    columns = m->getColumns();
    locX = path.front()->getCoordinates()[0];
    locY = path.front()->getCoordinates()[1];
    // print();
    // usleep(1000000);
    std::list<Vertex *>::iterator i;
    // int lenght =  path.size();
    for(i = path.begin(); i != path.end(); i++) {
        matrix[locX][locY] = '.';
        locX = (*i)->getCoordinates()[0];
        locY = (*i)->getCoordinates()[1];
        matrix[locX][locY] = NORTH;
        // path.pop_front();
        print();
        usleep(1000000);
        system("clear");

    }
}

void Animation::print() {
    int r, c;
    printf("    ");
 for(int i=0;i<columns;i++) 
   printf("  %d ",i);
 printf("\n");
 printf("    ");
 for(int i=0;i<columns;i++) 
   printf("+---");
 printf("+\n");
 for( r=0; r < rows ; r++ ) 
 {
 printf("  %d ",r);
   for( c=0; c < rows; c++ ) {
        if (matrix[r][c] == '*') 
        {
        printf( "|***" );
        }

        if (matrix[r][c] == 'x') 
        {
        printf( "| X " );
        }

        if (matrix[r][c] == '.') 
        {
        printf( "|   " );
        }
        
        if ( matrix[r][c] == '^' ) {
            printf("| ^ ");
        }
        if ( matrix[r][c] == 'v' ) {
            printf("| v ");
        }
        if ( matrix[r][c] == '>' ) 
        {
            printf( "| > " );
            // if (Rob1.getFacing() == NORTH) 
            // {
            //   printf("| ^ ");
            // }
            // else if (Rob1.getFacing() == NORTHEAST) 
            // {
            //   printf("| / ");
            // }
            // else if (Rob1.getFacing() == EAST) 
            // {
            //   printf("| > ");
            // }
            // else if (Rob1.getFacing() == SOUTHEAST) 
            // {
            //   printf("| \\ ");
            // }
            // else if (Rob1.getFacing() == SOUTH) 
            // {
            //   printf("| v ");
            // }
            // else if (Rob1.getFacing() == SOUTHWEST) 
            // {
            //   printf("| %% ");
            // }
            // else if (Rob1.getFacing() == WEST) 
            // {
            //   printf("| < ");
            // }        
            // else if (Rob1.getFacing() == NORTHWEST) 
            // {
            //   printf("| # ");
            // }//end of if(Rob1...)else
        }//end of if(matrix....)
 
   }//end of for(c)
   printf( "|\n" );
   printf("    ");
   for(int i=0;i<columns;i++) 
     printf("+---");
   printf("+\n");
 }//end of for(r)
}
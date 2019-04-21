#include <unistd.h>
#include <iostream>
#include "Animation.hpp"
#include <map>
using namespace std;
Animation::Animation(Matrix *m, list<Vertex*> path) {
    matrix = m->getMatrix();
    rows = m->getRows();
    columns = m->getColumns();
    locX = path.front()->getCoordinates()[0];
    locY = path.front()->getCoordinates()[1];
    faces[0] = '>';  // EAST
    faces[1] = '/';  // NORTHEAST
    faces[2] = '^';  // NORTH
    faces[3] = '#';  // NORTHWEST
    faces[4] = '<';  // WEST
    faces[5] = '%';  // SOUTHWEST
    faces[6] = 'v';   // SOUTH
    faces[7] = '\\'; // SOUTHEAST
    face = 0;
    // print();
    // usleep(1000000);
    std::list<Vertex *>::iterator i;
    // int lenght =  path.size();
    for(i = path.begin(); i != path.end(); i++) {
        int auxX = locX;
        int auxY = locY;
        matrix[locX][locY] = '.';
        locX = (*i)->getCoordinates()[0];
        locY = (*i)->getCoordinates()[1];
        turn(auxX, auxY);
        matrix[auxX][auxY] = '.';
        matrix[locX][locY] = faces[face];
        // path.pop_front();
        print();
        usleep(200000);
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
            if ( matrix[r][c] == '/' ) {
                printf("| / ");
            }
            if ( matrix[r][c] == '%' ) {
                printf("| %% ");
            }
            if ( matrix[r][c] == '\\' ) {
                printf("| \\ ");
            }
            if ( matrix[r][c] == '#' ) {
                printf("| # ");
            }
            if ( matrix[r][c] == '<' ) {
                printf("| < ");
            }
            if ( matrix[r][c] == 'v' ) {
                printf("| v ");
            }
            if ( matrix[r][c] == '>' ) 
            {
                printf( "| > " );
            }//end of if(matrix....)
 
        }//end of for(c)
   printf( "|\n" );
   printf("    ");
   for(int i=0;i<columns;i++) 
     printf("+---");
   printf("+\n");
 }//end of for(r)
}

void Animation::turn(int auxX, int auxY) {
    char rFace;
    if(auxY < locY) {
        if(auxX < locX) {
            rFace = '\\';
        } else if (auxX > locX) {
            rFace = '#';
        } else {
            rFace = '>';
        }
    } else if (auxY > locY){
        if(auxX < locX) {
            rFace = 'v';
        } else if (auxX > locX) {
            rFace = '%';
        } else {
            rFace ='<';
        }

    } else {
        if(auxX < locX) {
            rFace = 'v';
        } else {
            rFace = '^';
        } 
    }

    while (rFace != faces[face]) {
        face = (face + 1 ) % 8;
        matrix[auxX][auxY] = faces[face];
        print();
        usleep(200000);
        system("clear");
    }
}
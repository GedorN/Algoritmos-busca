#pragma once
#include <stdio_ext.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <list>
#include "Vertex.hpp"
#include "Matrix.hpp"
 

class Animation {
    private:
        int rows;
        int columns; 
        int locX;
        int locY;
        int facing;
        char **matrix;
        char faces[8];
        int face;
    public:
        Animation(Matrix* m, list<Vertex*> path);
        void execute();
        int getX();
        int getY();
        void print();
        void turn(int, int);

};
#pragma once
#include <stdio_ext.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <list>
#include "Vertex.hpp"
#include "Matrix.hpp"
 
#define ROBOT       26
#define WALL        27
#define TARGET	    28
#define NONE        -1
 
#define MAX_ROWS    20
#define MAX_COLS    20
 
#define EAST		0
#define NORTHEAST	1
#define NORTH '^'
#define NORTHWEST       3
#define WEST		4
#define SOUTHWEST       5
#define SOUTH		'v'
#define SOUTHEAST	7

#define CLOCKWISE    100
#define COUNTERCLOCK 101

class Animation {
    private:
        int rows;
        int columns; 
        int locX;
        int locY;
        int facing;
        char **matrix;
    public:
        Animation(Matrix* m, list<Vertex*> path);
        void execute();
        int getX();
        int getY();
        void print();

};
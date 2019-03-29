#include "List.hpp"
#include"AdjacencyList.hpp"
#include "Matrix.hpp"
#include<stdlib.h>
#include "stdio_ext.h"
#include<iostream>
// #includelist>
using namespace std;

Vertex* beginPlayer = NULL;
char** getMatrixFromFile(FILE* file);
void printList(List *list, int n);
void createAdjacencyList();

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
    adjl.print();
}

void createAdjacencyList () {
    FILE* file = nullptr;
    List *list = new List();
    int counter = 1;
    

    int rows = 0,
        columns = 0;
    file = fopen("Env.txt", "r");
    if (file == nullptr) {
        cout<< "Arquivo não pode ser aberto" << endl;
        exit(9);
    }
    char **matrix = getMatrixFromFile(file); 
    rewind(file);

    fscanf(file, "%d\n", &rows);
    fscanf(file, "%d\n", &columns);
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%2c", matrix[i][j]);
        }
        putchar('\n');
    }

    for (int i = 1; i < rows - 1; i++) {
        for(int j = 1; j < columns - 1; j++) {
            // cout<< "Vou acessar a função"<< endl;
            if(matrix[i][j] == '.') {
                cout<<"Acessei" << endl;
                cout<< i << ' ' << j << endl;
                Vertex *v = new Vertex();
                v->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(v);
                
                if (matrix[i - 1][j - 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(l);
                    cout<< "Adicionando : " << "ce" << endl;
                }
                if (matrix[i - 1][j] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(l);
                    cout<< "Adicionando : " << "cr" << endl;
                }
                if (matrix[i - 1][j + 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(l);
                    cout<< "Adicionando : " << "cd" << endl;
                }
                if (matrix[i][j - 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(l);
                    cout<< "Adicionando : " << "re" << endl;
                }
                if (matrix[i][j + 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(l);
                    cout<< "Adicionando : " << "rd" << endl;
                }
                if (matrix[i + 1][j - 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(l);
                    cout<< "Adicionando : " << "be" << endl;
                }
                if (matrix[i + 1][j] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(l);
                    cout<< "Adicionando : " << "br" << endl;
                }
                if (matrix[i + 1][j + 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[counter - 1] = *list[counter - 1].insert(l);
                    cout<< "Adicionando : " << "bd" << endl;
                }

                cout<< "counter: "<< counter << endl;
                list = (List*)realloc(list, ++counter * sizeof(List));
                cout<<"fim realloc" << endl;
            }
        }
        
    }
    cout<< "fim tudo" << endl;
    fclose(file);   

    // printList(list, counter);
    
}   

char** getMatrixFromFile(FILE* file) {
    int rows = 0,
        columns = 0;
    fscanf(file, "%d\n", &rows);
    fscanf(file, "%d\n", &columns);

    char **matrix;

    matrix = (char**)malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(sizeof(char) * columns);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = fgetc(file);
        }
        fscanf(file, "\n");
    }
    return matrix;
}

void printList(List *list, int n) {
    cout<< "xsdfdfoi" << endl;
    cout<< sizeof(list) << endl;
    for (int i = 0; i < n; i++ ) {
        list[i].print();
    }

}
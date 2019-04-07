#include "AdjacencyList.hpp"
#include<cmath>

AdjacencyList::AdjacencyList(Matrix* matrixObj) {
    lenght = 0;
    int rows = matrixObj->getRows();
    int columns = matrixObj->getColumns();
    char **matrix = matrixObj->getMatrix();
    vertexList = new Vertex[rows * columns];

    

    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if( matrix[i][j] == '.' || matrix[i][j] == '>' || matrix[i][j] == 'x') {
                vertexList[lenght].setCoordinates(i, j);
                vertexList[lenght].setContent(matrix[i][j]);
                
                lenght++;
            }
        }
    }


    for (int i = 0; i < lenght; i++) {
        for(int j = 0; j < lenght; j++) {
           if (i != j) {
               if (std::abs(vertexList[i].getCoordinates()[0] - vertexList[j].getCoordinates()[0]) <= 1 && std::abs(vertexList[i].getCoordinates()[1] - vertexList[j].getCoordinates()[1]) <= 1) {
                   vertexList[i].setNeighborhood(j);
               }
           }
        }
    }
}

AdjacencyList::~AdjacencyList() {
    cout<< "Destruindo Adjacency List" << endl;
    delete [] vertexList;
}

int AdjacencyList::getLenght() {
    return lenght;
}

void AdjacencyList::print() {
    for (int i = 0; i < lenght; i++ ) {
        vertexList[i].print();
    }
}

Vertex* AdjacencyList::getList() {
    return vertexList;
}
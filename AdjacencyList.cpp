#include "AdjacencyList.hpp"

AdjacencyList::AdjacencyList(Matrix* matrixObj) {
    lenght = 1;
    list = new List();
    int rows = matrixObj->getRows();
    int columns = matrixObj->getColumns();
    char **matrix = matrixObj->getMatrix();

    for (int i = 1; i < rows - 1; i++) {
        for(int j = 1; j < columns - 1; j++) {
            // cout<< "Vou acessar a função"<< endl;
            if(matrix[i][j] == '.') {
                cout<<"Acessei" << endl;
                cout<< i << ' ' << j << endl;
                Vertex *v = new Vertex();
                v->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(v);
                
                if (matrix[i - 1][j - 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(l);
                    cout<< "Adicionando : " << "ce" << endl;
                }
                if (matrix[i - 1][j] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(l);
                    cout<< "Adicionando : " << "cr" << endl;
                }
                if (matrix[i - 1][j + 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(l);
                    cout<< "Adicionando : " << "cd" << endl;
                }
                if (matrix[i][j - 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(l);
                    cout<< "Adicionando : " << "re" << endl;
                }
                if (matrix[i][j + 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(l);
                    cout<< "Adicionando : " << "rd" << endl;
                }
                if (matrix[i + 1][j - 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(l);
                    cout<< "Adicionando : " << "be" << endl;
                }
                if (matrix[i + 1][j] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(l);
                    cout<< "Adicionando : " << "br" << endl;
                }
                if (matrix[i + 1][j + 1] == '.') {
                    Vertex *l = new Vertex();
                    l->setCoordinates(i, j);
                    list[lenght - 1] = *list[lenght - 1].insert(l);
                    cout<< "Adicionando : " << "bd" << endl;
                }

                cout<< "lenght: "<< lenght << endl;
                list = (List*)realloc(list, ++lenght * sizeof(List));
                cout<<"fim realloc" << endl;
            }
        }
        
    }
}

AdjacencyList::~AdjacencyList() {
    cout<< "Destruindo Adjacency List" << endl;
    free(list);
}

void AdjacencyList::print() {
    for (int i = 0; i < lenght; i++ ) {
        list[i].print();
    }
}
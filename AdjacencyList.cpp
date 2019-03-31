#include "AdjacencyList.hpp"

AdjacencyList::AdjacencyList(Matrix* matrixObj) {
    lenght = 0;
    list = new List();
    int rows = matrixObj->getRows();
    int columns = matrixObj->getColumns();
    char **matrix = matrixObj->getMatrix();

    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            // cout<< "Vou acessar a função"<< endl;
            if(matrix[i][j] == '.' || matrix[i][j] == '>' || matrix[i][j] == 'x') {
                cout<<"Acessei==========================" << endl;
                cout<< "(" << i << ", " << j << ")" << " = " << matrix[i][j]<< endl;
                Vertex *v = new Vertex();
                v->setCoordinates(i, j);
                v->setContent(matrix[i][j]);
                list[lenght].insert(v);
                // delete(v);
                
                if(i - 1 >= 0 && j - 1 >= 0)
                    if (matrix[i - 1][j - 1] == '.' || matrix[i - 1][j - 1] == '>' || matrix[i - 1][j - 1] == 'x') {
                        Vertex *l = new Vertex();
                        l->setCoordinates(i - 1, j - 1);
                        l->setContent(matrix[i - 1][j - 1]);
                        list[lenght].insert(l);
                        cout<< "Adicionando : " << "ce" << endl;
                    }
                if(i - 1  >= 0)
                    if (matrix[i - 1][j] == '.' || matrix[i - 1][j] == '>' || matrix[i - 1][j] == 'x') {
                        Vertex *l = new Vertex();
                        l->setCoordinates(i - 1, j);
                        l->setContent(matrix[i - 1][j]);
                        list[lenght].insert(l);
                        cout<< "Adicionando : " << "cr" << endl;
                    }
                if(i - 1 >= 0 && j + 1 < columns)
                    if (matrix[i - 1][j + 1] == '.' || matrix[i - 1][j + 1] == '>' || matrix[i - 1][j + 1] == 'x') {
                        Vertex *l = new Vertex();
                        l->setCoordinates(i - 1, j + 1);
                        l->setContent(matrix[i - 1][j + 1]);
                        list[lenght].insert(l);
                        cout<< "Adicionando : " << "cd" << endl;
                    }
                if (j - 1 >= 0)
                    if (matrix[i][j - 1] == '.' || matrix[i][j - 1] == '>' || matrix[i][j - 1] == 'x') {
                        Vertex *l = new Vertex();
                        l->setCoordinates(i, j - 1);
                        l->setContent(matrix[i][j - 1]);
                        list[lenght].insert(l);
                        cout<< "Adicionando : " << "re" << endl;
                    }
                if(j + 1 < columns)
                    if (matrix[i][j + 1] == '.' || matrix[i][j + 1] == '>' || matrix[i][j + 1] == 'x') {
                        Vertex *l = new Vertex();
                        l->setCoordinates(i, j + 1);
                        l->setContent(matrix[i][j + 1]);
                        list[lenght].insert(l);
                        cout<< "Adicionando : " << "rd" << endl;
                    }
                if(j - 1 >= 0 && i + 1 < rows)
                    if (matrix[i + 1][j - 1] == '.' || matrix[i + 1][j - 1] == '>' || matrix[i + 1][j - 1] == 'x') {
                        Vertex *l = new Vertex();
                        l->setCoordinates(i + 1, j - 1);
                        l->setContent(matrix[i + 1][j - 1]);
                        list[lenght].insert(l);
                        cout<< "Adicionando : " << "be" << endl;
                    }
                if(i + 1 < rows)
                    if (matrix[i + 1][j] == '.' || matrix[i + 1][j] == '>' || matrix[i + 1][j] == 'x') {
                        Vertex *l = new Vertex();
                        l->setCoordinates(i + 1, j);
                        l->setContent(matrix[i + 1][j]);
                        list[lenght].insert(l);
                        cout<< "Adicionando : " << "br" << endl;
                    }
                if(i + 1 < rows && j + 1 <columns)
                    if (matrix[i + 1][j + 1] == '.' || matrix[i + 1][j + 1] == '>' || matrix[i + 1][j + 1] == 'x') {
                        Vertex *l = new Vertex();
                        l->setCoordinates(i + 1, j + 1);
                        l->setContent(matrix[i + 1][j + 1]);
                        list[lenght].insert(l);
                        cout<< "Adicionando : " << "bd" << endl;
                    }
                list[lenght].print();
                lenght++;
                cout<< "lenght: " << lenght << endl;
                // delete v;   
                list = (List*)realloc(list, (lenght + 1) * sizeof(List));
            }
        }


    }
}

AdjacencyList::~AdjacencyList() {
    cout<< "Destruindo Adjacency List" << endl;
    free(list);
}

int AdjacencyList::getLenght() {
    return lenght;
}

void AdjacencyList::print() {
    for (int i = 0; i < lenght; i++ ) {
        list[i].print();
    }
}

List* AdjacencyList::getList() {
    return list;
}

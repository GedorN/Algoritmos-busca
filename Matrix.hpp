#pragma once

class Matrix {
    private:
        char** matrix;
        int rows;
        int columns;
    public:
    Matrix(char* maze);
    ~Matrix();
    char** getMatrix();
    int getRows();
    int getColumns();
    void print();
};
#include<iostream>
using namespace std;
typedef int Coordinate;
/*o char pode ser necessário ou não... não sei ainda*/
class List {
    private:
        // char spot;
        Coordinate x;
        Coordinate y;
        List* next;
    public:
        List();
        List(Coordinate x, Coordinate y);
        List* insert(Coordinate x, Coordinate y);
        int listSize();
        void print();
        void remove(Coordinate sport);
        void destroyAll(List* list);
};

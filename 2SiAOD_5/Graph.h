#ifndef MYHOMEWORK_GRAPH_H
#define MYHOMEWORK_GRAPH_H

#include <iostream>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int size); // size - размерность матрицы
    void set(unsigned int m, unsigned int n);
    void find(unsigned int vert);
    void printEulerLoop();
    void print();
void printMatrix();
private:
unsigned int size; // количество вершин
bool **matrix; // матрица смежности
stack<unsigned int> visited; // стек посещенных вершин
stack<unsigned int> euler; // стек вершин эйлерова цикла
};

#endif

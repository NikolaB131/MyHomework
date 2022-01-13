#ifndef MYHOMEWORK_GRAPH_H
#define MYHOMEWORK_GRAPH_H

class Graph {
public:
    Graph(const int n);
    void print();
private:
    bool **matrix; // матрица смежности
};

#endif

#include "Graph.h"

Graph::Graph(int size) {
    this->size = size;
    matrix = new bool* [size]; // выделение памяти под массив указателей (под первую координату)
    for (int i = 0; i < size; i++) {
        matrix[i] = new bool [size]; // выделение памяти под значения (под вторую координату)
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = false;
        }
    }
}

void Graph::set(unsigned int m, unsigned int n) { // m - строка, n - столбец
    if (m <= size && n <= size) {
        matrix[m - 1][n - 1] = true;
        matrix[n - 1][m - 1] = true;
    }
}

void Graph::find(unsigned int vert) {
    for (int i = 0; i < size; i++) {
        if (matrix[vert][i]) { // берем первую попавшеюся вершину
            matrix[vert][i] = false; // удаляем ребро между vert и i
            matrix[i][vert] = false;
            visited.push(i);
            find(i);
        }
    }
    if (!visited.empty()) {
        euler.push(visited.top());
        visited.pop();
    }
    if (!visited.empty()) {
        find(visited.top());
    }
}

void Graph::printEulerLoop() {
    // Проверка на условие существование эйлерова цикла
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j]) {
                count++;
            }
        }
        if (count % 2 == 1) { // если степень вершины не чётна
            cout << "В графе не существует эйлерова цикла!\n\n";
            return;
        }
        count = 0;
    }

    visited.push(0); // начальная точка
    find(0); // обход вершин до того как не будет найден тупик
    cout << "Эйлеров цикл:";
    while (!euler.empty()) {
        cout << ' ' << euler.top() + 1;
        euler.pop();
    }
}

void Graph::print() {
    for (int i = 0; i < size; ++i) {
        cout << "Вершина " << i + 1 << " соединена с вершинами:";
        for (int j = 0; j < size; j++) {
            if (matrix[i][j]) {
                cout << ' ' << j + 1;
            }
        }
        cout << endl;
    }
}

void Graph::printMatrix() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

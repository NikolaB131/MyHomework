#ifndef MYHOMEWORK_HASHTABLE_H
#define MYHOMEWORK_HASHTABLE_H

#include <iostream>
#include <string>
using namespace std;

struct HashTable {
public:
    HashTable();
    int hashFunc(string key);
    void add(string key, int offset);
    void remove(string key);
    int find(string key); // возвращает индекс
    void rehash();
    void print();

    struct Element {
        Element* pNext = nullptr; // указатель на следующий элемент
        string key;
        int offset = 0;
    };

    Element* table; // массив
    int size = 10; // размер массива
    int filled = 0; // количество записей
};

#endif

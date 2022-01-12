#ifndef MYHOMEWORK_TABLEANDFILEMANAGER_H
#define MYHOMEWORK_TABLEANDFILEMANAGER_H

#include "Hashtable.h"
#include <fstream>
#include <cstring>

class TableAndFileManager {
public:
    TableAndFileManager(string sourceFileName, string binaryFileName);
    void add(string data);
    string get(string key); // получить дынные по ключу
    void remove(string key);
private:
    string binaryFileName;
    HashTable hashTable;
    int currentOffset = 0;
};

#endif

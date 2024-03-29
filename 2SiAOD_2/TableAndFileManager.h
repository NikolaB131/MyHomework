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
    HashTable hashTable;
private:
    string binaryFileName;
    string sourceFileName;
    int currentOffset = 0;
};

#endif

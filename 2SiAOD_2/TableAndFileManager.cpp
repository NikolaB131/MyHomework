#include "TableAndFileManager.h"


TableAndFileManager::TableAndFileManager(string sourceFileName, string binaryFileName) {
    this->binaryFileName = binaryFileName;
    this->sourceFileName = sourceFileName;

    ifstream sourceFile("..\\2SiAOD_2\\" + sourceFileName); // открываем файл на чтение
    if (!sourceFile.is_open()) {
        cout << sourceFileName << " не может быть открыт!";
        return;
    }
    fstream binFile("..\\2SiAOD_2\\" + binaryFileName, fstream::binary | fstream::out); // запись
    if (!binFile.is_open()) {
        cout << binaryFileName << " не может быть открыт!";
        return;
    }
    // Перевод исходного файла в двоичный файл и в хеш таблицу
    string data;
    while (getline(sourceFile, data)) {
        add(data);
    }
    binFile.close();
    sourceFile.close();
}

void TableAndFileManager::add(string data) {
    // Добавление ключа и смещения в таблицу
    string key = data.substr(0, 9);
    hashTable.add(key, currentOffset);
    currentOffset++;

    // Добавление данных в бинарный файл
    ofstream binFile("..\\2SiAOD_2\\" + binaryFileName, ofstream::binary | ofstream::app); // запись
    char buf[50] = {};
    data = data.substr(10); // 10, т.к. в UTF-8 русские символы занимают 2 байта
    strcpy(buf, data.c_str()); // конвертирование строки в массив char
    binFile.write(buf, sizeof(buf));
    binFile.close();
}


string TableAndFileManager::get(string key) {
    if (hashTable.find(key) == -1) {
        cout << "\nЗаписи с таким ключом " << key << " не существует!";
        return "";
    }

    ifstream binFile("..\\2SiAOD_2\\" + binaryFileName, ifstream::binary); // чтение
    // поиск необходимого элемента в цепочке
    HashTable::Element* tempElement = &hashTable.table[hashTable.find(key)];
    while (tempElement->key != key) {
        tempElement = tempElement->pNext;
    }
    char data[50];
    binFile.seekg(tempElement->offset * sizeof(data), ios::beg); // перемещение курсора в нужную позицию бинарного файла
    binFile.read(data, sizeof(data));
    binFile.close();
    return data;
}


void TableAndFileManager::remove(string key) {
    ifstream sourceFile("..\\2SiAOD_2\\" + sourceFileName); // открываем файл на чтение
    if (!sourceFile.is_open()) {
        cout << sourceFileName << " не может быть открыт!";
        return;
    }
    fstream binFile("..\\2SiAOD_2\\" + binaryFileName, fstream::binary | fstream::out); // запись
    if (!binFile.is_open()) {
        cout << binaryFileName << " не может быть открыт!";
        return;
    }
    // Перевод исходного файла за исключением удаленной записи в двоичный файл и в хеш таблицу
    hashTable = *(new HashTable);
    currentOffset = 0;

    string data;
    while (getline(sourceFile, data)) {
        if (data.substr(0, 9) != key) {
            add(data);
        }
    }
    binFile.close();
    sourceFile.close();
}

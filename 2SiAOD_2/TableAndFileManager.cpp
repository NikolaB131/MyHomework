#include "TableAndFileManager.h"

TableAndFileManager::TableAndFileManager(string sourceFileName, string binaryFileName) {
    this->binaryFileName = binaryFileName;

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
    string data, tableTemp;
    while (getline(sourceFile, data)) {
        add(data);
    }
    binFile.close();
    sourceFile.close();

//    binFile.open("..\\2SiAOD_2\\" + binaryFileName, ofstream::binary | fstream::in); // чтение
//    while (!binFile.eof()) {
//        char buf[50] = {};
//        binFile.read(buf, 50 * sizeof(char));
//        for (int i = 0; i < 50; i++) {
//            cout << buf[i];
//        }
//        cout << endl;
//    }
//    binFile.close();
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
    ifstream binFile("..\\2SiAOD_2\\" + binaryFileName, ifstream::binary); // чтение
    int offset = hashTable.table[hashTable.find(key)].offset; // поиск смещения по ключу

    char data[50];
    binFile.seekg(offset * sizeof(data), ios::beg); // перемещение курсора в нужную позицию бинарного файла
    binFile.read(data, sizeof(data));
    binFile.close();
    return data;
}


void TableAndFileManager::remove(string key) {
    // Удаление ключа из таблицы
    hashTable.remove(key);

    // Удаление данных из бинарного файла
    ofstream binFile("..\\2SiAOD_2\\" + binaryFileName, ofstream::binary); // запись
    int offset = hashTable.table[hashTable.find(key)].offset; // поиск смещения по ключу

    char data[2] = {1, 2}; // пустой массив
    binFile.seekp(offset * sizeof(data), ios::beg); // перемещение курсора в нужную позицию бинарного файла
    binFile.write(data, sizeof(data));
    binFile.close();
}

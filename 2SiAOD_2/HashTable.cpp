#include "Hashtable.h"

HashTable::HashTable() {
    table = new Element[size];
}

void HashTable::add(string key, int offset) {
    if ((float)(filled + 1) / (float) size > 0.75) { // проверка коэффициента нагрузки
        rehash(); // выполняем рехеширование
    }
    int i = hashFunc(key);
    if (table[i].key.empty()) {
        table[i].key = key;
        table[i].offset = offset;
    } else { // разрешение коллизий методом цепочки
        Element* temp = &table[i];
        while (temp->pNext != nullptr) { // поиск свободного места
            temp = temp->pNext;
        }
        // добавление нового элемента в конец цепочки
        temp->pNext = new Element;
        temp->pNext->key = key;
        temp->pNext->offset = offset;
    }
    filled++; // увеличение заполненных ячеек
}

void HashTable::remove(string key) {
    int resultOfSearch = find(key);
    if (resultOfSearch != -1) {
        Element* temp = &table[resultOfSearch];
        if (temp->key == key) { // если необходимый ключ первый в цепочке
            if (temp->pNext == nullptr) { // если элемент под этим индексом только один
                table[resultOfSearch].key = "";
                table[resultOfSearch].offset = 0;
            } else {
                // делаем следующий элемент цепочки головным
                temp = temp->pNext;
                table[resultOfSearch] = *temp;
            }
        } else { // если необходимый ключ где-то дальше
            while (temp->pNext->key != key) {
                temp = temp->pNext;
            }
            Element* temp2 = temp->pNext->pNext;
            temp->pNext = temp2;
        }
        filled--; // уменьшение заполненных ячеек
    } else {
        cout << "\nЭлемента с ключом " << key << " не существует!\n";
    }
}

void HashTable::rehash() {
    HashTable newTable;
    newTable.size = size * 2;
    // создание новой таблицы с новым размером
    newTable.table = new Element[newTable.size];
    for (int i = 0; i < size; i++) { // рехеширование
        if (!table[i].key.empty()) {
            Element* temp = &table[i];
            while (temp) {
                newTable.add(temp->key, temp->offset);
                temp = temp->pNext;
            }
        }
    }
    // замена старой таблицы на новую
    size = newTable.size;
    table = newTable.table;
}

void HashTable::print() {
    for (int i = 0; i < size; i++) {
        if (!table[i].key.empty()) { // не выводить пустые ячейки
            cout << "Индекс " << i << ':';
            // обход цепочки
            Element* temp = &table[i];
            while (temp) {
                cout << " [Ключ: " << temp->key << " Offset: " << temp->offset << "]";
                if (temp->pNext != nullptr) {
                    cout << ',';
                }
                temp = temp->pNext;
            }
            cout << endl;
        }
    }
    cout << endl;
}

int HashTable::find(string key) {
    for (int i = 0; i < size; i++) {
        if (table[i].key == key) {
            return i;
        }
        // поиск в цепочке
        Element* temp = table[i].pNext;
        while (temp != nullptr) {
            if (temp->key == key) {
                return i;
            }
            temp = temp->pNext;
        }
    }
    return -1;
}

int HashTable::hashFunc(string key) {
    // хеш - сумма всех цифр номера авто
    int temp = stoi(key.substr(2, 6));
    return (temp / 100 + temp / 10 % 10 + temp % 10) % size;
}

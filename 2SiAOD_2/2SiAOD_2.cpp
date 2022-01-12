#include "TableAndFileManager.h"

int main() {
//    HashTable hashTable;
//    hashTable.add("n000nn", 6);
//    hashTable.add("n001nn", 7);
//    hashTable.add("n002nn", 8);
//    hashTable.add("n003nn", 99);
//    hashTable.add("n004nn", 95);
//    hashTable.add("n005nn", 96);
//    hashTable.add("n006nn", 97);
//    hashTable.print();
//    hashTable.add("n040nn", 98);
//    hashTable.print();
//    hashTable.remove("n040nn");
//    hashTable.print();

    TableAndFileManager tableAndFileManager("sourcefile.txt", "binfile.bin");
    cout << tableAndFileManager.get("т034мк");
    tableAndFileManager.remove("т034мк");
//    tableAndFileManager.add("а695ка Mazda_cx5 Иванова_Елена");

    return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file;
    file.open("..\\sortA.txt", fstream::binary | fstream::in | fstream::out); // in - чтение, out - запись
    if (!file.is_open())
        cout << "Ошибка открытия файла!\n";
    else {
        cout << "Файл открыт!\n";

    }
    file.close();
    return 0;
}
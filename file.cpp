// Вариант 2: Преобразование разделителей: превращение строк в столбцы слов.
// P.S. для русских букв запускать в VS.
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251); // кодировка для кириллицы
    SetConsoleOutputCP(1251);
    string temp;
    fstream MyFile;
    // создание или открытие (в том же каталоге, где и программа) файла на ввод и стирание из него предыдущих данных
    MyFile.open("..\\567.txt", fstream::out | fstream::trunc);
    if (!MyFile.is_open())
        cout << "Ошибка открытия файла!\n";
    else {
        cout << "Файл открыт!\n" << "Введите данные для записи: ";
        getline(cin, temp); // getline для того, чтобы учитывались пробелы
        MyFile << "Исходная строка: " << temp << "\nПреобразованные данные:"; // перенос данных из temp в файл
        cout << "Данные успешно записаны.\n";
        for (int i = 0; i < temp.length(); ++i) {
            MyFile << endl <<temp[i];
        }
    }
    MyFile.close(); // закрытие потока
    MyFile.open("..\\567.txt", fstream::in); // открытие файла на чтение
    if (!MyFile.is_open())
        cout << "Ошибка чтения файла!\n";
    else {
        cout << "Чтение файла!\n";
        while (!MyFile.eof()) {
            getline(MyFile, temp);
            cout << temp << endl;
        }
    }
    MyFile.close(); // закрытие потока
    cout << "Файл закрыт.";
    return 0;
}

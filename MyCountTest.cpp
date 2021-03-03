#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int choice = 0;
    fstream MyFile;
    do {
        cout << "1. Просмотреть\n2. Записать\n3. Выход\n";
        cin >> choice;
        if (choice == 1) {
            MyFile.open("MyCountTest.txt", fstream::in);
            if (!MyFile.is_open())
                cout << "Ошибка чтения файла!\n";
            else {
                cout << "Чтение файла!\n";
                string timeLeft, timeNeed, timeToday;
                for (int i = 0; i < 3; ++i) {
                    if (i == 0)
                        MyFile >> timeLeft;
                    else if (i == 1)
                        MyFile >> timeNeed;
                    else
                        MyFile >> timeToday;
                }
                cout << "Осталось учить: " << stoi(timeNeed) / 24 << " дней " << stoi(timeNeed) % 24 << " часов";
                cout << "\nВ среднем необходимо учить в день: " << float(stoi(timeNeed)) / float(stoi(timeLeft));
                cout << "\nПотратил времени на изучение сегодня: " << timeToday << endl;
            }
            MyFile.close();
        } else if (choice == 2) {
            MyFile.open("MyCountTest.txt", fstream::in);
            if (!MyFile.is_open())
                cout << "Ошибка записи файла!\n";
            else {
                cout << "Запись в файл!\n";
                string timeLeft, timeNeed;
                int timeToday;
                for (int i = 0; i < 2; ++i) {
                    if (i == 0)
                        MyFile >> timeLeft;
                    else
                        MyFile >> timeNeed;
                }
                MyFile.close();
                MyFile.open("MyCountTest.txt", fstream::out | fstream::trunc);
                cout << "Введите время в часах, проведенное за учебой сегодня: ";
                cin >> timeToday;
                MyFile << stoi(timeLeft) - 1 << endl << stoi(timeNeed) - timeToday << endl << timeToday;
                cout << "Файлы записаны!\n";
            }
            MyFile.close();
        }
    }
    while (choice != 3);
    return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "typeinfo"

using namespace std;

int main() {
    // Задача 3.1 "Заем"
    /*double S, n, p, r, total;
    cout << "Введите сумму займа: ";
    cin >> S;
    cout << "Введите срок займа: ";
    cin >> n;
    cout << "Введите процент займа: ";
    cin >> p;
    r = p / 100;
    if (S > 0 && n > 0) {
        if (p != 0) {
            total = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        }
        else
            total = (S / (12 * n));
        cout << "Месячная выплата составит: " << to_string(total).substr(0, to_string(total).find(".")) <<
        " рублей " << to_string(round(total * 100) / 100).substr(to_string(round(total * 100) / 100).find(".") + 1, 2) << " копеек";
    }
    else
        cout << "Введите положительные числа!";*/

    // Задача 3.2 "Ссуда"
    /*double S, m, n, r;
    cout << "Введите сумму займа: ";
    cin >> S;
    cout << "Введите сумму месячной выплаты: ";
    cin >> m;
    cout << "Введите срок займа: ";
    cin >> n;
    m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
    cout << m;*/

    // Задача 3.3 "Копирование файла"
    /*string temp;
    fstream MyFile;
    MyFile.open("123.txt");
    while(!MyFile.eof()) {
        getline(MyFile, temp);
        cout << temp << endl;
    }
    MyFile.close();*/

    // Задаача 3.4 "Фильтр"
    string temp;
    fstream MyFile;
    MyFile.open("123.txt");
    while(!MyFile.eof()) { // get() возвращает true если нашелся символ
        getline(MyFile, temp);
        for (int i = 0; i != temp.length() ; ++i) {
            if (isdigit(temp[i])) {
                cout << temp[i];
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    MyFile.close();


    /*string fileName, temp;
    fstream MyFile;
    cout << "Введите название файла: ";
    cin >> fileName;
    cin.ignore(256, '\n');
    MyFile.open(fileName + ".txt", fstream::in | fstream::out | fstream::app);
    if (!MyFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        getline(cin, temp);
        MyFile << temp << endl;
    }
    MyFile.close();
    MyFile.open(fileName + ".txt", fstream::in);
    while (!MyFile.eof()) {
        getline(MyFile, temp);
        cout << temp << endl;
    }
    MyFile.close();*/
    return 0;
}

#include "QueryPerformanceCounter.h" // для подсчета времени
#include <iostream>
#include <string>
using namespace std;

int main() {
    double counter; // счетчик времени
    bool check = true;
    string result;

    int n;
    cout << "Введите порядок матрицы: ";
    cin >> n;

    int x[n][n];
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) { // ввод массива
        for (int j = 0; j < n; ++j) {
            cin >> x[i][j];
        }
    }

    cout << "Введенный массив:\n";
    for (int i = 0; i < n; i++) { // вывод массива на экран
        for (int j = 0; j < n; ++j) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

    StartCounter();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // сравнение первого элемента строки с последним и т.д.
            if (x[i][j] != x[i][n - j - 1]) {
                check = false; // если пара элементов не совпала
            }
        }
        if (check) { // если все пары в строке совпали
            result += ", " + to_string(i + 1);
        }
        // восстановление значения для проверки следующей строки
        check = true;
    }
    counter = GetCounter();

    cout << "Строки-палиндромы:" << result.substr(1);
    cout << "\nЗатраченное время (в мс): " << counter;
    return 0;
}
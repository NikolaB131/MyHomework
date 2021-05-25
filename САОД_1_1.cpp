#include "QueryPerformanceCounter.h" // для подсчета времени
#include <iostream>
using namespace std;

double counter; // счетчик времени
// заполнение массива случайными числами
void fillArray(int *x, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        x[i] = rand() % 10;
    }
}

void printArray(int *x, int n) { // вывод массива на экран
    for (int i = 0; i < n; ++i) {
        cout << " " << x[i];
    }
}

void delFirstMethod(int *x, int *n, int key) { // первый метод
    StartCounter();
    int i = 0;
    while (i <= *n) {
        if (x[i] == key) {
            // перезапись текущего элемента следующим
            for (int j = i; j < *n - 1; j++) {
                x[j] = x[j + 1];
            }
            (*n)--;
        }
        else {
            i++;
        }
    }
    counter = GetCounter();
}

void delSecondMethod(int *x, int *n, int key) { // второй метод
    StartCounter();
    int j = 0;
    for (int i = 0; i < *n; i++) {
        x[j] = x[i];
// если текущий элемент не равен удаляемому, перейти к следующему
        if (x[i] != key) {
            j++;
        }
    }
    *n = j;
    counter = GetCounter();
}

int main() {
    int n, key, choice1, choice2;
    cout << "Введите количество элементов исходного массива: ";
    cin >> n;
    int *x = new int[n]; // выделение динамической памяти в куче

    cout << "1 - заполнить массив самому, 2 - функцией rand(): ";
    cin >> choice1;
    if (choice1 == 1) {
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            x[i] = temp;
        }
    }
    else if (choice1 == 2)
        fillArray(x, n);

    cout << "Исходный массив:";
    printArray(x, n);

    cout << "\nВведите удаляемый элемент: ";
    cin >> key;

    cout << "Выберите метод удаления элементов (1 или 2): ";
    cin >> choice2;
    if (choice2 == 1)
        delFirstMethod(x, &n, key);
    else if (choice2 == 2)
        delSecondMethod(x, &n, key);

    cout << "Преобразованный массив:";
    printArray(x, n);

    cout << "\nЗатраченное время (в мс): " << counter;
    delete[] x;
    return 0;
}

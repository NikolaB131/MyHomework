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

void insertionSort(int *x, int n) {
    StartCounter();
    for (int i = 1; i < n; i++) { // со 2 элемента, т.к. 1 вставлен
        int temp = x[i]; // запоминаем текущий элемент
        int j = i - 1;
        // пока элемент слева больше текущего элемента
        while (j >= 0 && x[j] > temp) {
            // если элемент слева больше текущего, сдвигаем его вправо
            x[j + 1] = x[j]; // перезапись правого элемента левым
            j--; // сравниваем следующий элемент
        }
        // помещаем текущий элемент в освободившуюся позицию
        x[j + 1] = temp;
    }
    counter = GetCounter();
}

int main() {
    int n, choice;
    cout << "Введите количество элементов исходного массива: ";
    cin >> n;
    int *A = new int[n];

    cout << "1 - заполнить массив самому\n2 - функцией rand()\nВыбор: ";
    cin >> choice;
    if (choice == 1) {
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            A[i] = temp;
        }
    }
    else if (choice == 2)
        fillArray(A, n);

    cout << "Исходный массив:";
    printArray(A, n);

    insertionSort(A, n);

    cout << "\nОтсортированный массив:";
    printArray(A, n);

    cout << "\nЗатраченное время (в мс): " << counter;
    return 0;
}
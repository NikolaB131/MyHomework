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

int counterCompare = 0, counterReplace = 0;
void exchangeSort(int *x, int n) {
    StartCounter();
    // два цикла, чтобы обработать весь массив
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            counterCompare++;
            if (x[j] > x[j + 1]) {
                counterReplace++;
                int temp = x[j]; // замена
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
    counter = GetCounter();
}

void insertionSort(int *x, int n) {
    StartCounter();
    for (int i = 1; i < n; i++) { // со 2 элемента, т.к. 1 вставлен
        int k = i;
        // пока меньший элемент не стоит перед большим
        while (k > 0 && x[k - 1] > x[k]) {
            int temp = x[k]; // меняем элементы местами
            x[k - 1] = x[k];
            x[k] = temp;
            // для проверки того, нужно ли продолжать менять элементы
            k--;
        }
    }
    counter = GetCounter();
}
int main() {
    int n, choice1;
    cout << "Введите количество элементов исходного массива: ";
    cin >> n;
    int *A = new int[n];

    cout << "1 - заполнить массив самому, 2 - функцией rand(): ";
    cin >> choice1;
    if (choice1 == 1) {
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            A[i] = temp;
        }
    }
    else if (choice1 == 2)
        fillArray(A, n);

    cout << "Исходный массив:";
    printArray(A, n);

    insertionSort(A, n);

    cout << "\nОтсортированный массив:";
    printArray(A, n);

    cout << "\nКоличество сравнений: " << counterCompare << endl;
    cout << "Количество перемещений: " << counterReplace << endl;
    cout << "Затраченное время (в мс): " << counter;
    return 0;
}
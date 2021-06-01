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

void fillArrayAscending(int *x, int n) {
    for (int i = 0; i < n; ++i) {
        x[i] = i + 1;
    }
}

void fillArrayDescending(int *x, int n) {
    for (int i = 0; i < n; ++i) {
        x[i] = n - i;
    }
}

long long int counterCompare = 0, counterReplace = 0;
void exchangeSort(int *x, int n) {
    StartCounter();
    // два цикла, чтобы обработать весь массив
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) { // n выполнений
            counterCompare++;
            if (x[j] > x[j + 1]) { // если текущий больше следующего
                counterReplace += 3;
                int temp = x[j]; // замена
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
    counter = GetCounter();
}

int main() {
    int n, choice;
    cout << "Введите количество элементов исходного массива: ";
    cin >> n;
    int *A = new int[n];

    cout << "1 - заполнить массив самому\n2 - функцией rand()\n3 - заполнить по возрастанию\n4 - заполнить по убыванию"
            "\nВыбор: ";
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
    else if (choice == 3)
        fillArrayAscending(A, n);
    else if (choice == 4)
        fillArrayDescending(A, n);

    cout << "Исходный массив:";
    printArray(A, n);

    exchangeSort(A, n);

    cout << "\nОтсортированный массив:";
    printArray(A, n);

    cout << "\nКоличество сравнений: " << counterCompare;
    cout << "\nКоличество перемещений: " << counterReplace;
    cout << "\nКоличество сравнений и перемещений: " << counterCompare + counterReplace;
    cout << "\nЗатраченное время (в мс): " << counter;
    delete[] A;
    return 0;
}

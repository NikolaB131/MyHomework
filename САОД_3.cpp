#include "QueryPerformanceCounter.h" // для подсчета времени
#include <iostream>
using namespace std;

double counter; // счетчик времени
long long int counterCompare = 0, counterReplace = 0; // подсчет операций
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

void exchangeSort(int *x, int n) {
    StartCounter();
    bool swap;
    // два цикла, чтобы обработать весь массив
    for (int i = 0; i < n - 1; i++) {
        swap = false;
        for (int j = 0; j < n - 1 - i; j++) { // n выполнений
            counterCompare++;
            if (x[j] > x[j + 1]) { // если текущий больше следующего
                counterReplace += 3;
                int temp = x[j]; // замена
                x[j] = x[j + 1];
                x[j + 1] = temp;
                swap = true;
            }
        }
        if (!swap) {// условие Айверсона
            counter = GetCounter();
            return;
        }
    }
    counter = GetCounter();
}

void shakerSort(int *x, int n) {
    StartCounter();
    int left = 0; // первый элемент
    int right = n - 1; // последний элемент
    while (left < right) { // пока границы не сомкнутся
        for (int i = left; i < right; i++) { // слева направо
            counterCompare++;
            if (x[i + 1] < x[i]) {
                counterReplace += 3;
                int temp = x[i]; // замена
                x[i] = x[i + 1];
                x[i + 1] = temp;
            }
        }
        right--; // уменьшение правой границы
        for (int i = right; i > left; i--) { // справа налево
            counterCompare++;
            if (x[i - 1] > x[i]) {
                counterReplace += 3;
                int temp = x[i]; // замена
                x[i] = x[i - 1];
                x[i - 1] = temp;
            }
        }
        left++; // увеличение левой границы
    }
    counter = GetCounter();
}

void merge(int *x, int l, int m, int r) // сливает вместе два подмассива
{
    int n1 = m - l + 1; // длина левого подмассива
    int n2 = r - m; // длина правого подмассива
    int *L = new int[n1]; // Создание временных массивов
    int *R = new int[n2];
    for (int i = 0; i < n1; i++) // Копирование данных в левый подмассив
        L[i] = x[l + i];
    for (int j = 0; j < n2; j++) // Копирование данных в правый подмассив
        R[j] = x[m + 1 + j];

    int i = 0; // индекс для левого подмассива
    int j = 0; // индекс для правого подмассива
    int k = l; // индекс для будущего массива из двух подмассивов

    // пока не дойдем до конца L или R, выбрать наименьший элемент из L[i] и R[j]
    // и поставить его на правильное место в основном массиве
    while (i < n1 && j < n2) {
        counterCompare++;
        if (L[i] <= R[j]) { // элемент в левом подмассиве меньше или равен элементу в правом подмассиве
            counterReplace++;
            x[k] = L[i]; // перенос элемента из левого подмассива в будущий массив
            i++;
        } else { // элемент в левом подмассиве больше элемента в правом подмассиве
            counterReplace++;
            x[k] = R[j]; // перенос элемента из правого подмассива в будущий массив
            j++;
        }
        k++; // элемент в будущем массиве упорядочен, переход к следующему
    }
    // если закончились элементы в одном из подмассивов, перенести оставшиеся элементы из подмассива в основной массив
    while (i < n1) { // если остались элементы в левом подмассиве
        counterReplace++;
        x[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) { // если остались элементы в правом подмассиве
        counterReplace++;
        x[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeinSort(int *x, int l, int r) { // вызывается рекурсивно
    if (l < r) { // если в текущем массиве не 1 элемент
        int m = l + (r - l) / 2; // середина массива (в меньшую сторону при четной длине)
        mergeinSort(x, l, m); // разделение текущей левой части массива
        mergeinSort(x, m + 1, r); // разделение текущей правой части массива
        merge(x, l, m, r); // слияние двух текущих подмассивов
    }
}

void mergeSort(int *x, int n) {
    StartCounter();
    mergeinSort(x, 0, n - 1);
    counter = GetCounter();
}

int main() {
    int n, choice1, choice2;
    cout << "Введите количество элементов исходного массива: ";
    cin >> n;
    int *A = new int[n];

    cout << "1 - заполнить массив самому\n2 - функцией rand()\n3 - заполнить по возрастанию\n4 - заполнить по убыванию"
            "\nВыбор: ";
    cin >> choice1;
    if (choice1 == 1) {
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            A[i] = temp;
        }
    }
    else if (choice1 == 2)
        fillArray(A, n);
    else if (choice1 == 3)
        fillArrayAscending(A, n);
    else if (choice1 == 4)
        fillArrayDescending(A, n);

    cout << "Исходный массив:";
    printArray(A, n);

    cout << "\n1 - Простого обмена с условием Айверона\n2 - Шейкерная\n3 - Слиянием\nВыбор: ";
    cin >> choice2;
    if (choice2 == 1)
        exchangeSort(A, n);
    else if (choice2 == 2)
        shakerSort(A, n);
    else if (choice2 == 3)
        mergeSort(A, n);

    cout << "Отсортированный массив:";
    printArray(A, n);

    cout << "\nКоличество сравнений: " << counterCompare;
    cout << "\nКоличество перемещений: " << counterReplace;
    cout << "\nКоличество сравнений и перемещений: " << counterCompare + counterReplace;
    cout << "\nЗатраченное время (в мс): " << counter;
    delete[] A;
    return 0;
}

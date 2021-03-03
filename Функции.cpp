#include <iostream>

using namespace std;

int ok; // глобальная переменная в отличии от локальной при создании инициализируется значением по умолчанию

double square(double a, double b) {
    return a * b;
}

// массив в функцию
void FillArray(int array[], const int size) { // передается только указатель, а не весь массив
    // найти размер массива с помощью sizeof не получится, т.к. указатель указывает только первый элемент массива
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }
}

void PrintArray(int array[], const int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void foo(int a, int b); // прототип фунцкии

void foo2(int a = 3) { // передача аргумента в функцию по умолчанию
    for (int i = 0; i < a; ++i) {
        cout << "7" << endl;
    }
}

int Sum(int a, int b) { // первая перегрузка функции Sum
    return a + b;
}

double Sum(double a, double b) { // вторая перегрузка функции Sum
    return a + b;
}

// шаблонная функция, class(typename) указывает тип с которым может работать функция
// 2 типа(T1, T2) могут принимать любые значения, автоопределяются
template <class T1, class T2> T1 Sum2(T1 a, T2 b) { // функция возвращает тип T1, принимает T1 и T2
    return a + b;
}

int main() {
    // обычная функция
    double x, y;
    cout << "Площадь квадрата со сторнами 5 и 6: ";
    cout << square(5, 6) << endl;

    // массив в функцию
    const int SIZE = 10;
    int a[SIZE];
    FillArray(a, SIZE);
    PrintArray(a, SIZE);

    // прототипы функций
    foo(0, 1);

    // аргументы (параметры) по умолчанию
    foo2();

    // перегрузка функции
    cout << Sum(2, 2) << "\t";
    cout << Sum(1.1, 2.4) << endl;

    // шаблонная функция
    cout << Sum2(1.1, 1) << endl;
    return 0;
}

void foo(int a, int b) {
    cout << "Меня вызвали! " << a << " " << b << endl;
}
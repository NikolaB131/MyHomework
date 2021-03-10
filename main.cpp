#include <iostream>
using namespace std;

void foo(int *pb, int *pc) { // указатель - это адрес, в функцию передается адрес
    (*pb)++; // идет работа уже не с копией b, а непосредственно с нею самой, т.к. мы передали её адрес
    *pc = 89;
}

void foo2(int *a, int *b) { // меняет переменные метами с помощтю указателей
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5;
    int *pa = &a; // запись адресаа памяти a в указатель pa
    cout << a << "\t" << pa << endl;
    *pa = 10;
    cout << a << "\t" << pa << endl << endl;

    int arr[5] {1, 5, 2, 7, 9};
    for (int i = 0; i < 5; ++i)
        cout << &arr[i] << "\t" << arr[i] << endl;
    cout << endl << arr << endl; // адрес первого элемента массива (имя массива есть указатель на его первый эелемент)

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";
    // это тоже самое что и
    cout << "\t";
    for (int i = 0; i < 5; ++i)
        cout << *(arr + i) << " ";
    cout << endl << endl;

    int b = 0, c = 0;
    foo(&b, &c); // &, т.к. нужно передать адрес в функцию
    cout << b << endl << c << endl;

    int a1 = 5;
    int b1 = 2;
    foo2(&a1, &b1);
    cout << a1 << endl << b1;

    // Ссылки
    int aa = 7;
    int &aaRef = aa;
    return 0;
}
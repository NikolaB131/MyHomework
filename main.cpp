#include <iostream>
using namespace std;

void Foo(int *pb) {
    *pb++;
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
    cout << endl;

    int b
    return 0;
}
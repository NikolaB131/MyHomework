#include <iostream>
using namespace std;

void delFirstMethod(int *x, int *n, int key) {
    int i = 1;
    while (i <= *n) {
        if (x[i] == key) {
            for (int j = i; j <= *n - 1; j++) // удаление
                x[j] = x[j + 1];
            (*n)--;
        }
        else
            i++;
    }
}

void fillArray(int *x, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i)
        x[i] = rand() % 10;
}

void printArray(int *x, int n) {
    for (int i = 0; i < n; ++i)
        cout << x[i] << endl;
}

int main() {
    int n, key;
    cout << "Введите количество элементов исходного  массива: ";
    cin >> n;
    int *x = new int[n];
    fillArray(x, n);
    cout << "Исходный массив:" << endl;
    printArray(x, n);
    cout << "Введите удалемый элемент: ";
    cin >> key;
    delFirstMethod(x, &n, key);
    cout << "Преобразованный массив:" << endl;
    printArray(x, n);
    return 0;
}
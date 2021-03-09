#include <iostream>
using namespace std;

void delFirstMethod(int *x[], int n, int key) {
    int i = 1;
    while (i <= n) {
        if (*x[i] == key) {
            cout << "del";
            for (int j = 0; j < n - 1; ++j)
                x[j] = x[j + 1];
            break;
            n--;
        }
        else
            i++;
    }
}

int main() {
    int n, key;
    cout << "Введите количество элементов исходного  массива: ";
    cin >> n;
    int *x = new int[n];
    srand(time(nullptr));
    cout << "Введите удалемый элемент: ";
    cin >> key;
    for (int i = 0; i < n; ++i)
        x[i] = rand() % 10;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; ++i)
        cout << x[i] << endl;
    delFirstMethod(x, n, key);
    return 0;
}
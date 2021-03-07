#include <iostream>
using namespace std;

void delFirstMethod(int x[], int n, int key) {
    int i = 1;
    while (i <= n) {
        if (x[i] == key) {
            // del
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
    int n;
    cout << "Введите количество элементов исходного  массива: ";
    cin >> n;
    srand(time(nullptr));
    cout << rand() % 10;
    return 0;
}
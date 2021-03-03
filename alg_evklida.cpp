#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    cout << a;
    return 0;
}
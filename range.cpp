// Ряды. Задача 2
#include <iostream>
#include <cmath>

using namespace std;

long double fact(int n) { // функция для нахождения факториала
    long double result = 1; // long, т.к. факториал может быть очень большим. double для дальнейшего использования
    for (int i = 2; i < n + 1; ++i)
        result *= i;
    return result;
}
int main() {
    int n;
    long double result = 0;
    cout << "Введите число слагаемых n: ";
    cin >> n;
    for (int i = 1; i < n + 1; ++i)
        result += fact(n + 1 - i) / sqrt(i * (pow(i,2) + 1) / 2); // формула из условия
    cout << "Сумма из n слагаемых равна: " << result;
    return 0;
}
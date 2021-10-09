#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string decToBin(int x) { // перевод из десятичной СС в двоичную
    string result;
    while (true) {
        result = to_string(x % 2) + result;
        if (x / 2 == 0) {
            break;
        }
        x /= 2;
    }
    return result;
}

int operator1(int x) {
    int mask = 10; // 1010
    return x | mask; // 11111
}

int operator2(int x) {
    int mask = 65295; // 1111 1111 0000 1111
    return x & mask;
}

int operator3(int x) {
    return x << 5; // *32
}

int operator4(int x) {
    return x >> 5; // /32
}

int operator5(int x, int n) {
    int mask = 32768; // 1000 0000 0000 0000
    mask = mask >> (15 - n); // сдвиг вправо в начальной маске под необходимый номер бита
    return x | mask;
}

int main() {
    int x = 0x15; // 10101
    int n;
    cout << "Оператор 1: " << "Было: " << decToBin(x) << ", стало: " << decToBin(operator1(x));
    cout << "\nВведите значение для 2 оператора в десятичном формате: ";
    cin >> x;
    cout << "Оператор 2: " << "Было: " << decToBin(x) << ", стало: " << decToBin(operator2(x));
    cout << "\nВведите значение для 3 оператора в десятичном формате: ";
    cin >> x;
    cout << "Оператор 3: " << "Было: " << x << ", стало: " << operator3(x);
    cout << "\nВведите значение для 4 оператора в десятичном формате: ";
    cin >> x;
    cout << "Оператор 4: " << "Было: " << x << ", стало: " << operator4(x);
    cout << "\nВведите значение для 5 оператора в десятичном формате: ";
    cin >> x;
    cout << "Введенное число в двоичном формате: " << decToBin(x)
         << "\nВведите номер бита который необходмо установить в 1: ";
    cin >> n;
    cout << "Оператор 5: " << "Было:  " << decToBin(x) << "\n            Стало: " << decToBin(operator5(x, n));
    return 0;
}

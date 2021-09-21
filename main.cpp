#include <iostream>
#include <string>
using namespace std;

string decToBin(int x) {
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

int operator5(int x) {
    int mask = 65265; // ??
 }

int main() {
    int x = 0x15; // 10101
    cout << "Оператор 1: " << "Было: " << decToBin(x) << ", стало: " << decToBin(operator1(x));
    cout << "\nВведите значение для 2 оператора: ";
    cin >> x;
    cout << "Оператор 2: " << "Было: " << decToBin(x) << ", стало: " << decToBin(operator2(x));
    cout << "\nВведите значение для 3 оператора: ";
    cin >> x;
    cout << "Оператор 3: " << "Было: " << x << ", стало: " << operator3(x);
    cout << "\nВведите значение для 4 оператора: ";
    cin >> x;
    cout << "Оператор 4: " << "Было: " << x << ", стало: " << operator4(x);
    cout << "\nВведите значение для 5 оператора: ";
    cin >> x;
    cout << "Оператор 5: " << "Было: " << x << ", стало: " << operator5(x);
    return 0;
}

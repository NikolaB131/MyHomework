#include <iostream>
#include <string>
using namespace std;

int main() {
//    int a[10];
//    cout << "Введите числа массиа через пробел: ";
//    for (int i = 0; i < 10; i++) {
//        int temp;
//        cin >> temp;
//        a[i] = temp;
//    }
//    for (int i = 0; i < 10; i++) {
//        if (a[i] % 2 == 0) {
//            a[i] = 0;
//        }
//    }
//    cout << "Результат: ";
//    for (int i = 0; i < 10; i++) {
//        cout << a[i] << ' ';
//    }



//    string symbol, str;
//    cout << "Введите символ: ";
//    cin >> symbol;
//    if (symbol.size() == 1) {
//        cout << "Введите строку: ";
//        cin >> str;
//        if (str.size() > 1) {
//            if (str.find(symbol) == -1) {
//                cout << "Символ в строке не найден!";
//            }
//            else {
//                cout << "Номер символа в строке: " << str.find(symbol) + 1;
//            }
//        }
//    }


    int a[3][3];
    for (int i = 0; i < 3; i++) { // ввод матрицы
        for (int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }
    int opr = (a[0][0] + a[1][1] + a[2][2]) + (a[0][1] + a[1][2] + a[]);
    for (int i = 0; i < 3; i++) { // вывод матрицы
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << opr;
    return 0;
};
#include <iostream>

using namespace std;

int balls[100];
int counter = 0;

void perestanovka(int m, int n) {
    if (m == n - 1) { // ограничение массива(отброс мусорных значений)
        bool x = false;
        for (int i = 0; i < n; ++i) {
            if (balls[i] == i) { // поиск шарика, совпадающего с номером "вытаскивания"
                x = true;
                break; // как только такой нашелся, завершаем поиск
            }
        }
        if (!x) // если такого в массиве не нашлось
            return;
        for (int i = 0; i < n; ++i) // вывод ряда шариков, в которых есть нужный нам случай
           cout << balls[i] << " ";
        cout << endl;
        ++counter; // если такой случай есть, то записываем его
        return;
    }
    for (int i = m; i < n; ++i) {
        int temp = balls[i]; // перестановка элементов
        balls[i] = balls[m];
        balls[m] = temp;
        perestanovka(m + 1, n);
        temp = balls[i]; // перестановка элементов в исходнео положение
        balls[i] = balls[m];
        balls[m] = temp;
    }
}

int main() {
    int n;
    cout << "Введите количетсво шариков: ";
    cin >> n;
    for (int i = 0; i < n; ++i) // нумерация шариков
        balls[i] = i;
    for (int i = 0; i < n; ++i) // вывод первоначального ряда шариков
        cout << balls[i];
    cout << endl;
    perestanovka(0, n);
    cout << counter;
    return 0;
}
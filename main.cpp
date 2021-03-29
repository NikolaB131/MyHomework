#include <iostream>
#include <ctime>
using namespace std;

double time_spent;
void delFirstMethod(int *x, int *n, int key) {
    clock_t begin = clock();
    int i = 0;
    while (i <= *n) {
        if (x[i] == key) {
            for (int j = i; j < *n - 1; j++) // удаление
                x[j] = x[j + 1];
            (*n)--;
        }
        else
            i++;
    }
    clock_t end = clock();
    time_spent = ((double)(end - begin)) / CLOCKS_PER_SEC;
}

void delOtherMethod(int *x, int *n, int key) {
    int j = 0;
    for (int i = 0; i < *n; i++) {
        x[j] = x[i];
        if (x[i] != key)
            j++;
    }
    *n = j;
}

void fillArray(int *x, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i)
        x[i] = rand() % 10;
}

void printArray(int *x, int n) {
    for (int i = 0; i < n; ++i)
        cout << " " << x[i];
}

int main() {
    int task;
    do {
        cout << "Выберите задание (1 или 2): ";
        cin >> task;
    } while (task != 1 && task != 2);

    if (task == 1) { // Задание 1
        int n, key, choice;
        cout << "Введите количество элементов исходного  массива: ";
        cin >> n;
        int *x = new int[n];
        fillArray(x, n);
        cout << "Исходный массив:";
        printArray(x, n);
        cout << "\nВведите удалемый элемент: ";
        cin >> key;
        do {
            cout << "Выберите метод удаления элементов(1 или 2): ";
            cin >> choice;
        } while (choice != 1 && choice != 2);

        if (choice == 1) {
            delFirstMethod(x, &n, key);
        }
        else
            delOtherMethod(x, &n, key);
        cout << "Преобразованный массив:";
        printArray(x, n);
        cout << endl << "Затраченное время: " << time_spent;
    }
    else { // Задание 2
        bool check = true;
        string result;
        const int n = 4;
        int x[n][n] = {
                1, 3, 4, 4,
                2, 3, 3, 2,
                1, 0, 0, 1,
                0, 1, 0, 1
        };
        cout << "Введенный массив:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; ++j) {
                cout << x[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (x[i][j] != x[i][n - j - 1]) {
                    check = false;
                }
            }
            if (check) {
                result += " " + to_string(i + 1);
            }
            check = true;
        }
        cout << "Строки-палиндромы:" <<result;
    }
    return 0;
}
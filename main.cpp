#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "typeinfo"

using namespace std;

int main() {
    // Задание 1.1 "Имя"
    /*string name;
    cout << "Введите ваше имя: ";
    cin >> name;
    if (cin.fail()) {
        cout << "Вас зовут: " << name;
    }
    else
        cout << "Ошибка, введите строку!";*/

    // Задание 1.2 "Арифметика"
    /*float a, b;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    if (cin) {
        cout << "Сумма чисел: " << a + b;
        cout << "\nРазность чисел: " << a - b;
        cout << "\nПроизведение чисел: " << a * b;
        if (b != 0) {
            cout << "\nДеление a на b: " << a / b;
        }
        else
            cout << "\nДеление a на b: Деление на ноль!";
        if (a != 0) {
            cout << "\nДеление b на a: " << b / a;
        }
        else
            cout << "\nДеление b на a: Деление на ноль!";
    }
    else
        cout << "Ошибка, введите число!";*/

    // Задание 1.3 "Уравнение"
    /*float b, c;
    cout << "Уравнение вида bx+c=0\nВведите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;
    if (cin) {
        if (b == 0 and c == 0) {
            cout << "Бесконечное количество решений";
        }
        else if (b == 0) {
            cout << "Нет решений";
        }
        else
            if (-c / b != -0) {
                cout << -c / b;
            }
            else
                cout << "0";
    }
    else
        cout << "Ошибка, введите число!";*/

    // Задание 1.4 "Еще уравнение"
    /*double a, b, c, D;
    cout << "Уравнение вида ax^2+bx+c=0\nВведите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;
    if (cin) {
        if (a == 0)
        {
            if (b == 0 and c == 0) {
                cout << "Бесконечное количество решений";
            }
            else if (b == 0) {
                cout << "Нет решений";
            }
            else
            if (-c / b != -0) {
                cout << -c / b;
            }
            else
                cout << "0";
        }
        else
        {
            D = pow(b, 2) - 4 * a * c;
            if (D > 0) {
                cout << "x1 = " << (-b + sqrt(D)) / (a * 2);
                cout << "\nx2 = " << (-b - sqrt(D)) / (a * 2);
            }
            if (D < 0) {
                cout << "Корней нет";
            }
            if (a == 0 and b == 0 and c == 0) {
                cout << "Бесконечное количество решений";
            } else if (D == 0) {
                cout << "x1 = x2 = " << -b / (a * 2);
            }
        }
    }
    else
        cout << "Ошибка, введите число!";*/

    // Задание 1.5 "Лампа со шторой"
    /*string time, curtains, lamp;
    cout << "Введите время стуок на улице(day или night): ";
    cin >> time;
    cout << "Раздвинуты ли шторы?(yes или no): ";
    cin >> curtains;
    cout << "Включена ли лампа?(yes или no): ";
    cin >> lamp;
    if (cin.fail()) {
        if ((time == "day" and curtains == "yes") or (lamp == "yes")) {
            cout << "В комнате светло!";
        }
        else
            cout << "В комнате тьма...";
    }
    else
        cout << "Ошибка, введите строку!";*/

    // Задача 2.1 "Конус"
    /*double R, r, h, l;
    cout << "Введите радиус большего основания: ";
    cin >> R;
    cout << "Введите радуис меньшего основания: ";
    cin >> r;
    cout << "Введите высоту: ";
    cin >> h;
    if (cin) {
        if (R > 0 && r > 0 && h > 0) {
            cout << "Объем усеченого конуса равен: " << (M_PI * h * (pow(R,2) + R * r + pow(r,2))) / 3 << " м^3\n";
            l = sqrt(pow(h,2) + pow(R - r,2));
            cout << "Полная площадь поверхности конуса равна: " << M_PI * (pow(R,2) + l * (R + r) + pow(r,2)) << "м^2";
        }
        else
            cout << "Введите числа большие нуля!";
    }
    else
        cout << "\nОшибка, введите число!";*/

    // Задача 2.2 "Разветвление"
    /*double x, a;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите a: ";
    cin >> a;
    if (cin) {
        if (abs(x) > 0 && abs(x) < 1.0) {
            cout << "w = " << a * log(abs(x));
        }
        else if (abs(x) >= 1 && sqrt(a - pow(x,2)) >= 0) {
            cout << "w = " << sqrt(a - pow(x,2));
        }
        else
            cout << "Ошибка, подлогарифмическое выражение меньше или равно нулю!";
    }
    else
        cout << "\nОшибка, введите число!";*/

    // Задача 2.3 "Функция"
    /*double x, y, b;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    cout << "Введите b: ";
    cin >> b;
    if (cin) {
        if (b - y > 0 && b - x >= 0) {
            cout << "z = " << log(b - y) * sqrt(b - x);
        }
        else
            cout << "Ошибка, подлогарифмическое выражение меньше или равно 0 или значение под корнем меньше 0!";
    }
    else
        cout << "\nОшибка, введите число!";*/

    // Задача 2.4 "Порядок"
    /*float N;
    cout << "Ведите N: ";
    cin >> N;
    if (cin) {
        if (N >= 0) {
            for (int i = int(floor(N) + 1); i != int(floor(N)) + 11; i += 1) {
                cout << i << " ";
            }
        }
        else if (N < 0 and N + 9 >= 0) { // Второе условие - проверка выхода за диапазон
            for (int i = int(floor(N)) + 1; i != int(floor(N)) + 11; i += 1) {
                if (i > 0) {
                    cout << i << " ";
                }
            }
        }
        else
            cout << "Последовательности для данного числа N не существует";
    }
    else
        cout << "Ошибка, введите число!";*/

    // Задача 2.5 "Табуляция"
    /*float x = -4;
    cout << "╔===================╗\n║    X    ║    Y    ║\n║=========║=========║\n";
    for (int i = 0; i != 17; ++i) {
        if (x <= 4) {
            double y = (pow(x, 2) - 2 * x + 2) / (x - 1);
            if (x != 1) {
                cout << "║" << setw(7) << setprecision(2) << fixed << x
                     << "  ║" << setw(7) << setprecision(2) << fixed << y << "  ║\n";
            }
            else
                cout << "║   1.00  ║   /0    ║\n";
            x += 0.5;
        }
    }
    cout << "╚===================╝";*/

    // Задача 3.1 "Заем"
    /*double S, n, p, r, total;
    cout << "Введите сумму займа: ";
    cin >> S;
    cout << "Введите срок займа: ";
    cin >> n;
    cout << "Введите процент займа: ";
    cin >> p;
    r = p / 100;
    if (S > 0 && n > 0) {
        if (p != 0) {
            total = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
        }
        else
            total = (S / (12 * n));
        cout << "Месячная выплата составит: " << to_string(total).substr(0, to_string(total).find(".")) <<
        " рублей " << to_string(round(total * 100) / 100).substr(to_string(round(total * 100) / 100).find(".") + 1, 2) << " копеек";
    }
    else
        cout << "Введите положительные числа!";*/

    // Задача 3.2 "Ссуда"
    /*double S, m, n, r;
    cout << "Введите сумму займа: ";
    cin >> S;
    cout << "Введите сумму месячной выплаты: ";
    cin >> m;
    cout << "Введите срок займа: ";
    cin >> n;
    m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
    cout << m;*/

    // Задача 3.3 "Копирование файла"
    /*string temp;
    fstream MyFile;
    MyFile.open("123.txt");
    while(!MyFile.eof()) {
        getline(MyFile, temp);
        cout << temp << endl;
    }
    MyFile.close();*/

    // Задаача 3.4 "Фильтр"
    string temp;
    fstream MyFile;
    MyFile.open("..\\123.txt");
    while(!MyFile.eof()) { // get() возвращает true если нашелся символ
        getline(MyFile, temp);
        for (int i = 0; i != temp.length() ; ++i) {
            if (isdigit(temp[i])) {
                cout << temp[i];
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    MyFile.close();


    /*string fileName, temp;
    fstream MyFile;
    cout << "Введите название файла: ";
    cin >> fileName;
    cin.ignore(256, '\n');
    MyFile.open(fileName + ".txt", fstream::in | fstream::out | fstream::app);
    if (!MyFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        getline(cin, temp);
        MyFile << temp << endl;
    }
    MyFile.close();
    MyFile.open(fileName + ".txt", fstream::in);
    while (!MyFile.eof()) {
        getline(MyFile, temp);
        cout << temp << endl;
    }
    MyFile.close();*/
    return 0;
}

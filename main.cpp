#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <typeinfo>

using namespace std;

int sign_x(int a) {
    if (a > 0)
        return 1;
    else if (a < 0)
        return -1;
    else
        return 0;
}
double rectangle(double a, double b) {
    return a * b;
}
double triangle(double b, double h) {
    return b * h / 2;
}
double circle(double R) {
    return M_PI * pow(R, 2);
}

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
            total = S / (12 * n);
        cout << "Месячная выплата составит: " << to_string(total).substr(0, to_string(total).find('.')) <<
        " рублей " << to_string(round(total * 100) / 100).substr(to_string(round(total * 100) / 100).find('.') + 1, 2) << " копеек";
    }
    else
        cout << "Введите положительные числа!";*/

    // Задача 3.2 "Ссуда" сдать
    /*double S, m, n, p;
    cout << "Введите сумму займа: ";
    cin >> S;
    cout << "Введите сумму месячной выплаты: ";
    cin >> m;
    cout << "Введите срок займа: ";
    cin >> n;
    p = 0.000001;
    if (S / m == n * 12) // обработка случая с нулевыми процентами
        cout << "0%";
    else {
        while ((p / 100 * S * pow(1 + p / 100, n)) / (12 * (pow(1 + p / 100, n) - 1)) <= m) // цикл подбора значений p, через формулу месячной выплаты
            p += 0.000001; // шаг подбора 0.000001
        cout << p << "%";
    }*/

    // Задача 3.3 "Копирование файла"
    /*string temp;
    fstream MyFile;
    MyFile.open("123.txt");
    while(!MyFile.eof()) {
        getline(MyFile, temp);
        cout << temp << endl;
    }
    MyFile.close();*/

    // Задача 3.4 "Фильтр"
    /*fstream MyFile;
    string temp, out, finalOut;
    int j, dotCount = 0;
    MyFile.open("..\\123.txt");
    while(!MyFile.eof()) {
        getline(MyFile, temp);
        for (int i = 0; i != temp.length(); ++i) { // Отсеивает числа и точки
            if (isdigit(temp[i]) || temp[i] == '.') {
                out += temp[i];
            }
            else
                out += " ";
        }
        while (out[j] != '\0') { // Чистит пробелы
            if (out[j] == ' ' && out[j + 1] == ' ') {
                out.replace(j, 1, "");
                j = -1;
            }
            j++;
        }
        j = 0;
        if (out[0] == ' ') // Убирает пробел в начале
            out.replace(0, 1, "");
        while (!out.empty()) { // Отсеивает неправильные числа с плавающей точкой
            temp = out.substr(0, out.find(' ')); // строка до пробела
            out = out.substr(temp.length() + 1); // Обрезает строку от temp до след. пробела
            for (int i = 0; i != temp.length() ; ++i) {
                if (temp[i] == '.')
                    dotCount++;
                if (temp[i] == '.' && temp[i + 1] == '\0')
                    dotCount++;
                if (temp[i] == '.' && temp[i - 1] == '\0')
                    dotCount++;
            }
            if (dotCount < 2) {
                finalOut += temp + " ";
            }
            dotCount = 0;
        }
        cout << finalOut << endl;
        finalOut = "";
    }
    MyFile.close();*/

    // Задача 3.5 "Сортировка букв"
    /*string a, aTemp;
    char temp;
    cin >> a;
    a = a.substr(0, 30);
    for (int j = 1; j < 30; ++j) {
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] - '0' > a[i + 1] - '0' && a[i + 1] != '\0') {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    for (int i = a.length(); i != 0; --i) {
        if (isupper(a[i])) {
            a = a.substr(i + 1) + a.substr(0, i + 1);
            break;
        }
    }
    cout << a;*/

    // Задача 4.1 "Файл"
    /*string temp;
    int tempOut, count = 0;
    fstream MyFile;
    MyFile.open("..\\234.txt", fstream::out | fstream::trunc);
    if (!MyFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        getline(cin, temp); // getline для того, чтобы учитывались пробелы
        MyFile << temp;
    }
    MyFile.close();
    MyFile.open("..\\234.txt", fstream::in);
    getline(MyFile, temp);
    for (int i = 0; i < temp.length(); ++i) {
        if (isdigit(temp[i]) && count < 10) {
            tempOut += temp[i] - '0';
            count++;
        }
    }
    cout << tempOut;
    MyFile.close();*/

    // Задача 4.2 "Знак числа" сдать
    /*int x;
    cout << "Введите число: ";
    cin >> x;
    cout << sign_x(x);*/

    // Задача 4.3 "Геометрические фигуры" сдать
    /*int selection;
    double a, b;
    cout << "Что будем вычислять?\n" << "1 - прямоугольник\n" << "2 - треугольник\n" << "3 - круг\n";
    cin >> selection;
    switch (selection) {
        case 1:
            cout << "Введите первую сторону: ";
            cin >> a;
            cout << "Введите вторую сторону: ";
            cin >> b;
            if (a > 0 && b > 0)
                cout << rectangle(a, b);
            else
                cout << "Ошибка!";
            break;
        case 2:
            cout << "Введите сторону: ";
            cin >> a;
            cout << "Введите высоту: ";
            cin >> b;
            if (a > 0 && b > 0)
                cout << triangle(a, b);
            else
                cout << "Ошибка!";
            break;
        case 3:
            cout << "Введите радиус: ";
            cin >> a;
            if (a > 0)
                cout << circle(a);
            else
                cout << "Ошибка!";
            break;
        default:
            cout << "Ошибка!";
    }*/

    // Задача 4.4 "Былая слава" сдать
    /*for (int i = 0; i < 6; i++) // 6 строк
    {
        for (int j = 0; j < 8; j++) // 8 раз, т.к. 8 столбцов
            cout << "* ";
        cout << "============================\n";
    }
    for (int i = 0; i < 7; i++) // И еще 7 строк
        cout << "============================================\n";*/

    // Задача 4.5 "Синусоида"


    // Задача 4.6 "Автоматный распознаватель" уточнить
    /*string a;
    int result;
    cout << "Введите римскую цифру: ";
    cin >> a;*/

    // Задача 4.7 "Генератор случайных чисел" уточнить


    // Задача 4.8 "Умножение матриц"
    /*double a[3][4] = {
            {5, 2, 0, 10},
            {3, 5, 2, 5},
            {20, 0, 0, 0}
    }; // 3 продавца, 4 товара
    double b[4][2] = {
            {1.20, 0.50},
            {2.80, 0.40},
            {5.00, 1.00},
            {2.00, 1.50}
    }; // цена за каждый товар и его комиссионные
    double c[3][2];
    c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0] + a[0][3] * b[3][0];
    c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1] + a[0][3] * b[3][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0] + a[1][3] * b[3][0];
    c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1] + a[1][3] * b[3][1];
    c[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0] + a[2][3] * b[3][0];
    c[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1] + a[2][3] * b[3][1];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            c[i, j] = 0;
            for (int k = 0; k < 4; ++k) {
                c[i, j] += a[i, k] * b[k, j];
            }
        }
    }
    cout << c[0][0] << " " << c[0][1] << endl;
    cout << c[1][0] << " " << c[1][1] << endl;
    cout << c[2][0] << " " << c[2][1] << endl;*/

    // Задача 4.9 "Системы счисления" уточнить
    return 0;
}

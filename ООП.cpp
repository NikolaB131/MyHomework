#include <iostream>
#include <string>

using namespace std;

class Human { // Human - тип данных, ыусловно говоря класс - это шаблон
public: // модификатор доступа, все в нем доступно везде
    string name; // поле класса = свойство класса
    int age = 1;
    int weight = 0;
    void print() { // метод класса = функция класса
        cout << "Имя: " << name << "\nВозраст: " << age << "\nВес: " << weight;
    }

    void hello() {
        cout << "age+xd= " << age + xd << endl;
    }

private: // модификатор доступа, все в нем доступно только внутри класса
    int xd = 5;
};

class Point {
public:
    int x; // поле класса
    int y;
    int z;
};

class Test { // геттеры и сеттеры
// это инкапсуляция, т.к. эти значения доступны только внутри класса
// пользователь работает только с тем, с чем мы ему разрешили работать(это и есть инкапсуляция)
private:
    int x = 0;
    int y = 0;

public:
    int GetX() { // геттер для поля x
        return x;
    }

    void SetX(int valueX) { // сеттер для поля x, получает на вход int valueX
        x = valueX;
    }

    void Print() {
        cout << "X = " << x << "\nY = " << y << endl;
    }
};

class CoffeeGrinder { // пример инкапсуляции
private:
    bool CheckVoltage() { // скрытый функционал кофемолки(доступа у нему не имеем)
        // что то проверяется
        return true; // возвращается значение, что все хорошо
    }

public:
    void Start() {
        if (CheckVoltage()) // в методе Start вызываем метод CheckVoltage
            cout << "hopa\n";
        else
            cout << "error\n";
    }
};

class PointConstructor {
private:
    int x;
    int y;

public:
    // конструктора по умолчанию нету, т.к. мы написали свой, значит без данных x и y мы не сможем создать обьект класса
    PointConstructor(int ValueX, int ValueY) { // конструктор (обязательно должен быть в public)
        x = ValueX;
        y = ValueY;
    }

    void Print() {
        cout << "x: " << x << "\ty: " << y << endl;
    }
};

int main() {
    Human firstHuman; // экземпляр класса Human = обьект класса Human
    firstHuman.name = "Ivanov Ivan";
    firstHuman.age = 30;
    firstHuman.weight = 100;
    firstHuman.print();
    cout << endl;
    firstHuman.hello();

    Human secondHuman;
    secondHuman.age = 42;
    secondHuman.name = "Said";
    secondHuman.weight = 65;

    Point a;
    a.x = 1;
    a.y = 3;
    a.z = 5;

    // геттеры и сеттеры
    Test b;
    b.SetX(5);
    cout << b.GetX() << endl;
    b.Print();

    // "реальный" пример инкапсуляции
    CoffeeGrinder machine;
    machine.Start();

    // конструктор класса
    PointConstructor FirstConstructor(1, 2); // преимущество в том, что не нужно использовать сеттеры
    FirstConstructor.Print();

    PointConstructor SecondConstructor(90, 55);
    SecondConstructor.Print();
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Human {
public:
    string GetName() {
        return name;
    };
    void SetName(string name) {
        this->name = name; // this - это адрес обьекта, по нему можно обращатся ко всем полям и методам класса
        // использование -> вместо . необходимо, т.к. this - это указатель
    }
private:
    string name;
};
class Student : public Human{
public:
    string group;
    void Learn() {
        cout << "Я учусь!\n";
    }
};
class ExtramuralStudent : public Student {
public:
    void Learn() {
        cout << "Я учусь меньше обычного студента\n";
    }
};


class A {
public:
    A() {
        cout << "Конструктор класса A\n";
    }
    ~A() {
        cout << "Деструктор класса A\n";
    }
};
class B  : public A{
public:
    B() {
        cout << "Конструктор класса B\n";
    }
    ~B() {
        cout << "Деструктор класса B\n";
    }
};
class C : public B{
public:
    C() {
        cout << "Конструктор класса C\n";
    }
    ~C() {
        cout << "Деструктор класса C\n";
    }
};


class A1 {
public:
    A1() {
        msg = "Пустое сообщение";
    }
    A1(string msg) {
        this->msg = msg; // this - это адрес обьекта, по нему можно обращатся ко всем полям и методам класса
    }
    void PrintMsg() {
        cout << msg << endl;
    }
private:
    string msg;
};
class B1 : public A1 {
public:
    B1() {} // ссылаетя на конструтор по умолчанию класса A1
    B1(string msg):A1(msg) {} // указываем какой конкретно конструктор необходимо вызвать, и передает туда значение msg
};

int main() {
    Student student1;
    student1.SetName("Макар");
    cout << student1.GetName() << endl;
    student1.Learn();
    ExtramuralStudent student2;
    student2.SetName("Кекс");
    cout << student2.GetName() << endl;
    student2.Learn();
    cout << endl;

    C c;
    cout << endl;

    A1 value1;
    value1.PrintMsg();
    B1 value2("йоу");
    value2.PrintMsg();
    cout << endl;
    return 0;
}
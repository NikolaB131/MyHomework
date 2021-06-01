#include <iostream>
using namespace std;

// по умолчанию все поля и методы private
// при наследовании если не указывать права доступа,
// то поля и методы класса наследуется как private
class MyClass {
    int a = 10;
};

// по умолчанию все поля и методы public
// при наследовании если не указывать права доступа,
// то поля и методы структуры наследуется как public
struct MyStruct {
    int a = 15;
};

int main() {
    MyClass m;
    MyStruct ms;
    cout << m.a;
    cout << ms.a;
    return 0;
}

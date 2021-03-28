#include <iostream>
using namespace std;

template<class T1, class T2>
class MyClass {
public:
    MyClass(T1 value, T2 value2) {
        this->value = value;
        this->value2 = value2;
    }
    void dataTypeSize() {
        cout << sizeof(value) << endl;
        cout << sizeof(value2) << endl;
    }
private:
    T1 value;
    T2 value2;
};

int main() {
    MyClass<int, double> a(5, 2.233);
    a.dataTypeSize();
    return 0;
}
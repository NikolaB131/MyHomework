#include <iostream>
using namespace std;

template<class T>
class SmartPointer {
public:
    SmartPointer(T *ptr) {
        this->ptr = ptr;
        cout << "Конструктор" << endl;
    }

    ~SmartPointer() {
        delete ptr;
        cout << "Деструктор" << endl;
    }

    T &operator * () { // Мы должны возвращать ссылку на эти данные, т.к. нам не нужна копия этих данных
        return *ptr;    // (мы просто не сможем их поменять, т.к. будет изменяться только копия)
    }
private:
    T *ptr;
};
int main() {
    SmartPointer<int> pointer = new int(5); // new int возвращает указатель, поэтому все будет работать
    *pointer = 71;
    cout << *pointer << endl;
    return 0;
}
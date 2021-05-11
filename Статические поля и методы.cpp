#include <iostream>
using namespace std;

class idGenerator {
public:
    idGenerator() {
        counter++;
        id = counter;
    }
    void getId() {
        cout << id << endl;
    }
    static int lol() { // статический метод можно вызывать без создания объекта класса
//      this    мы не можем обращатся к этим данным, т.к. они уникальны для каждого объекта(не static), а метод static
//      privet
        cout << "Статическая переменная: " << counter << endl;
        return 0;
    }
private:
    int id;
    static int counter; // переменная общая для всех объектов
    bool privet;
};
int idGenerator::counter = 0;


int main() {
    idGenerator::lol();
    idGenerator object1;
    idGenerator object2;
    object2.getId();
    object1.getId();

    idGenerator::lol();
    return 0;
}
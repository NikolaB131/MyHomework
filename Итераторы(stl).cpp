#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {1, 9, 44, 422, 654, 91};
    vector<int>::iterator it; // it - итератор, а все остальное тип данных (итератор будет конкретно типа int)
    it = myVector.begin(); // метод begin() возвращает итератор
    *it = 89;
    it++;
    cout << *it << endl; // метод begin (возвращает указатель на первый элемент)
    advance(it, 2);
    cout << *it << endl << endl;


    vector<int> myVector2 = {23, 6, 45, 427};
    for (vector<int>::iterator i = myVector2.begin(); i != myVector2.end(); i++) {
        cout << *i << " ";
    }
    cout << endl << endl;
    // есть const_iterator, с помощтью которого уже нельзя менять значения через него, так же есть cbegin() и cend()
    // есть reverse_iterator, так же есть rbegin() т rend()


    vector<int> myVector3 = {5, 123, 61, 43, 28};
    for (vector<int>::iterator i = myVector3.begin(); i != myVector3.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    vector<int>::iterator it3 = myVector3.begin();

    advance(it3, 3);
    myVector3.insert(it3, 999);

    for (vector<int>::iterator i = myVector3.begin(); i != myVector3.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    vector<int>::iterator itErase = myVector3.begin();
    myVector3.erase(itErase, itErase + 2); // удалит элементы с 1 по 2
    for (vector<int>::iterator i = myVector3.begin(); i != myVector3.end(); i++) {
        cout << *i << " ";
    }
    return 0;
}
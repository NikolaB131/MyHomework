#include <iostream>
#include <list>
using namespace std;

template <class T>
void PrintList(const list<T> &lst) { // list<T> - просто чтобы показать что мы передаем именно list
    for (auto i = lst.cbegin(); i != lst.cend(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    list<int> myList = {78, 15, 78, 43, 7, 78, 78, 78};
    cout << myList.size() << endl;
    myList.push_back(5);
    myList.push_front(8);

    list<int>::iterator it = myList.begin(); // begin() возвращает итератор, хранящий указатель на 1 элемент листа
    cout << *it << endl;
    PrintList(myList);
    myList.pop_front(); // удаляет первый элемент списка
    PrintList(myList);
    myList.unique(); // удалаяет рядом стоящие дубликаты
    PrintList(myList);
    myList.reverse();
    PrintList(myList);

    auto it2 = myList.begin();
    advance(it2, 3);
    myList.insert(it2, 99); // добавляет число в ячейку под индексом 3 (4 элемент), после выполнения этой операции,
    // итератор увеличивается на 1, т.к. весь лист увеличивается на 1 элемент
    PrintList(myList);
    myList.erase(it2); // it теперь 4 (то есть 5 элемент), соответственно удалится 5 элемент
    PrintList(myList);
    myList.remove(78);
    PrintList(myList);
    myList.assign(10, 2);
    PrintList(myList);

    list<int> myList2 = {1, 2, 3, 5};
    myList.assign(myList2.begin(), myList2.end()); // такая конструкция скопировала myList2 в myList
    PrintList(myList);
    return 0;
}
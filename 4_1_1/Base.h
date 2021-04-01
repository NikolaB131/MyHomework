#ifndef BASE_H
#define BASE_H
#include <string>
#include <list>
using namespace std;
class Base
{
public:
    Base(Base *ptr_parent = 0);
    void setName(string name);
    string getName();
    void setParent(Base *ptr_parent);
    void add_child(Base *ptr_child);
    list<Base *> childrens; // список указателей на потомков
    lsit<Base *>::iterator it_child; // итератор для списка потомков
private:
    string name;
    Base *ptr_parent; // указатель на головной обьект
};
#endif
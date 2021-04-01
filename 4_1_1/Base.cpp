#include "Base.h"
Base::Base(Base *ptr_parent)
{
    setName("Base");
    if (ptr_parent) // если указатель не равен 0
    {
        this->ptr_parent = ptr_parent; // присваивание указателя на текущий обьект к указателю, передаваемому через конструктор
        ptr_parent->add_child(this); // запись в родителя указатель на текущий обьект
    }
}

void Base::setName(string name) // методд определения имени обьекта
{
    this->name = name;
}

string Base::getName() // метод получения имени текущего обьекта
{
    return this->name;
}

void Base::setParent(Base *ptr_parent) // метод переопределения головного обьекта
{
    if (ptr_parent)
    {
        this->ptr_parent = ptr_parent;
        ptr_parent->add_child(this);
    }
}

void Base::add_child(Base *ptr_child)
{
    childrens.push_back(ptr_child); // запись указателя на потомка в списке потомков у родителя
}
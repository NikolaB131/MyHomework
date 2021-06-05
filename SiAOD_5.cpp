#include <iostream>
using namespace std;

class List {
public:
    ~List() {
        clear();
    }

    // перегрузка оператора [] для доступа по индексу
    int& operator[](const int index) {
        Node* current = first;
        int counter = 0;
        while (current) {
            if (counter == index) {
                return current->data;
            }
            current = current->nextNode;
            counter++;
        }
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        if (!size) { // если список пуст
            first = newNode;
        } else { // если список не пуст
            newNode->nextNode = first;
            first = newNode;
        }
        size++;
    }

    void print() {
        if (first) {
            Node* current = first;
            for (int i = 0; i < size; i++) {
                cout << current->data << ' ';
                current = current->nextNode;
            }
            cout << '\b';
        }
        cout << endl;
    }

    void deleteNode(int nodeNumber) {
        if (nodeNumber > 0 && nodeNumber <= size) {
            if (nodeNumber == 1) {
                Node* temp = first->nextNode;
                delete first;
                first = temp;
            } else {
                int counter = 1;
                Node* current = first;
                // посик элемента, стоящего перед удаляемым
                while (counter != nodeNumber - 1) {
                    current = current->nextNode;
                    counter++;
                }
                Node* temp = current->nextNode->nextNode;
                delete current->nextNode;
                current->nextNode = temp;
            }
            size--;
        }
    }

    void clear() {
        for (int i = 0; i < size; i++) {
            Node* temp = first;
            first = first->nextNode;
            delete temp;
        }
        size = 0;
    }

    void lastToFirst () {
        if (first->nextNode) {
            Node* last = first;
            while (last->nextNode->nextNode) {
                last = last->nextNode;
            }
            int temp = last->nextNode->data;
            last->nextNode->data = first->data;
            first->data = temp;
        }
    }

    friend void sortListHighest(List& list);
    friend void sortListLowest(List& list);
    friend void relocateWithLowestSort(List& L1, List& L2);
    friend void isListSortedAscending(List& list);
private:
    class Node {
    public:
        Node(int data, Node* nextNode = nullptr) {
            this->data = data;
            this->nextNode = nextNode;
        }
        Node* nextNode;
        int data;
    };
    Node* first = nullptr;
    int size = 0;
};

void sortListHighest(List& list) {
    int first, second;
    for (int i = 0; i < list.size - 1; i++) {
        for (int j = 0; j < list.size - 1 - i; j++) {
            if (list[j] < 10) {
                first = list[j];
            } else {
                first = list[j] / 10;
            }
            if (list[j + 1] < 10) {
                second = list[j + 1];
            } else {
                second = list[j + 1] / 10;
            }
            // если старший разряд первого числа больше страшего разряда
            // следующего числа
            if (first > second) {
                int temp = list[j]; // замена
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void sortListLowest(List& list) {
    for (int i = 0; i < list.size - 1; i++) {
        for (int j = 0; j < list.size - 1 - i; j++) {
            // если младший разряд первого числа больше младшего разряда
            // следующего числа
            if ((list[j] + 10) % 10 > (list[j + 1] + 10) % 10) {
                int temp = list[j]; // замена
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void generateList(List& list, int n) {
    cout << "Введите элементы списка L1: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp < 100) {
            list.push_front(temp);
        }
    }
    sortListHighest(list);
}

void generateRandomList(List& list, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        list.push_front(rand() % 100);
    }
    sortListHighest(list);
}

void relocateWithLowestSort(List& L1, List& L2) {
    if (L1.size) {
        for (int i = 0; i < L1.size; i++) {
            int temp = L1[i];
            L2.push_front(temp);
        }
        L1.clear();
        sortListLowest(L2);
    }
}

void isListSortedAscending(List& list) {
    if (list.size) {
        for (int i = 0; i < list.size - 1; i++) {
            if (list[i] > list[i + 1]) {
                cout << "Список L2 не отсортирован в порядке возрастания!";
                return;
            }
        }
        cout << "Список L2 отсортирован в порядке возрастания.";
    }
}

int main() {
    int n, choice;
    List L1, L2;
    cout << "Введите количество элементов нового списка: ";
    cin >> n;
    cout << "Выберите способ ввода элементов:"
            "\n1 - заполнить список L1 случайными элементами, упорядоченными в "
            "порядке возрастания старшей цифры\n2 - ввести элементы вручную\n";
    do {
        cin >> choice;
        if (choice == 1) {
            generateRandomList(L1, n);
        } else if (choice == 2) {
            generateList(L1, n);
        }
    } while (choice != 1 && choice != 2);
    cout << endl << "Список L1: ";
    L1.print();
    cout << "Список L2: ";
    L2.print();
    cout << endl;
    do {
        cout << "Выберите действие:\n1 - удалить элемент из списка L1\n"
                "2 - перенести все элементы из списка L1 в список "
                "L2 порядке возрастания младшей цифры\n3 - проверить упорядочен"
                " ли список L2 по возрастанию\n4 - поменять местами первый и "
                "последний элемент\n5 - выход\n";
        cin >> choice;
        switch (choice) {
            case 1:
                int temp;
                cout << "Введите номер удаляемого элемента: ";
                cin >> temp;
                L1.deleteNode(temp);
                break;
            case 2:
                relocateWithLowestSort(L1, L2);
                break;
            case 3:
                isListSortedAscending(L2);
                break;
            case 4:
                L1.lastToFirst();
                break;
            case 5:
                goto end;
            default:
                break;
        }
        cout << endl << endl << "Список L1: ";
        L1.print();
        cout << "Список L2: ";
        L2.print();
        cout << endl;
    } while (true);
    end:
    return 0;
}

#include <iostream>
#include "SiAOD_6.h"
using namespace std;

void BooksList::addBook(unsigned int stockNumber,
                        string dateOfIssue,
                        string dateOfReturn) {
    if (stockNumber) {
        Book* newBook = new Book();
        newBook->stockNumber = stockNumber;
        newBook->dateOfIssue = dateOfIssue;
        newBook->dateOfReturn = dateOfReturn;
        if (!first) { // если список пуст
            first = newBook;
        } else { // если список не пуст
            Book* current = first;
            while (current) {
                if (current->nextBook == nullptr) {
                    current->nextBook = newBook;
                    break;
                }
                current = current->nextBook;
            }
        }
    }
}

void BooksList::returnBook(unsigned int stockNumber) {
    if (stockNumber && first) {
        if (first->stockNumber == stockNumber) {
            Book* temp = first->nextBook;
            delete first;
            first = temp;
        } else {
            Book* current = first;
            while (current->nextBook) {
                if (current->nextBook->stockNumber == stockNumber) {
                    Book* temp = current->nextBook->nextBook;
                    delete current->nextBook;
                    current->nextBook = temp;
                    break;
                }
                current = current->nextBook;
            }
        }
    }
}

Data::~Data() {
    delete booksList;
}

BooksList BooksList::booksNotReturned(string date) {
    BooksList* booksNotReturnedList = new BooksList;
    Book* current = first;
    int dateDay = stoi(date.substr(0, 2));
    int dateMonth = stoi(date.substr(3, 2));
    int dateYear = stoi(date.substr(6, 4));
    int dateSum = dateDay + dateMonth * 31 + dateYear * 365;
    while (current) {
        int returnDay = stoi(current->dateOfReturn.substr(0, 2));
        int returnMonth = stoi(current->dateOfReturn.substr(3, 2));
        int returnYear = stoi(current->dateOfReturn.substr(6, 4));
        if (returnDay + returnMonth * 31 + returnYear * 365 < dateSum) {
            booksNotReturnedList->addBook(current->stockNumber,
                                          current->dateOfIssue,
                                          current->dateOfReturn);
        }
        current = current->nextBook;
    }
    return *booksNotReturnedList;
}

Node::Node(unsigned int readerNumber) {
    data.readerNumber = readerNumber;
}

List::~List() {
    while (first) {
        Node* temp = first->nextNode;
        delete first;
        first = temp;
    }
}

void List::printFromLeft() {
    cout << "Номера читателей библиотеки слева направо: ";
    if (first) {
        Node* current = first;
        while (current) {
            cout << current->data.readerNumber << ' ';
            current = current->nextNode;
        }
        cout << '\b';
    }
}

void List::printFromRight() {
    cout << "Номера читателей библиотеки справа налево: ";
    if (first) {
        Node* current = last;
        while (current) {
            cout << current->data.readerNumber << ' ';
            current = current->prevNode;
        }
        cout << '\b';
    }
}

void List::printBooksNotReturned(Node* reader, string date) {
    if (reader->data.booksList->booksNotReturned(date).first) {
        cout << "|Книги, не возвращенные читателем в срок|\n";
        Book* currentBook = reader->data.booksList->booksNotReturned(date).first;
        while (currentBook) {
            cout << "Инвентарный номер книги: " << currentBook->stockNumber
                 << endl << "Дата выдачи книги:   " << currentBook->dateOfIssue
                 << endl << "Дата возврата книги: " << currentBook->dateOfReturn
                 << endl;
            currentBook = currentBook->nextBook;
        }
        cout << endl;
    } else {
        cout << "\n|Книги, не возвращенные читателем в срок отсутствуют|\n\n";
    }
}

void List::printReader(Node *reader, string date) {
    cout << "|Информация о читателе №" << reader->data.readerNumber << '|'
         << endl << "|Книги на руках|\n";
    Book* currentBook = reader->data.booksList->first;
    while (currentBook) {
        cout << "Инвентарный номер книги: " << currentBook->stockNumber <<
             endl << "Дата выдачи книги:   " << currentBook->dateOfIssue << endl
             << "Дата возврата книги: " << currentBook->dateOfReturn << endl;
        currentBook = currentBook->nextBook;
    }
    cout << endl;
    printBooksNotReturned(reader, date);
    cout << endl;
}

void List::printAllReaders(string date) {
    Node* current = first;
    while (current) {
        printReader(current, date);
        current = current->nextNode;
    }
}

void List::add(unsigned int readerNumber) {
    if (readerNumber) {
        Node* newNode = new Node(readerNumber);
        if (!first) { // если список пуст
            first = newNode;
            last = newNode;
        } else { // если список не пуст
            last->nextNode = newNode;
            newNode->prevNode = last;
            last = newNode;
        }
    }
}

Node* List::find(unsigned int readerNumber) {
    if (readerNumber) {
        Node* current = first;
        while (current) {
            if (current->data.readerNumber == readerNumber) {
                return current;
            }
            current = current->nextNode;
        }
    }
    return nullptr;
}

void List::randomGenerate(unsigned int numberOfReaders, string date) {
    srand(time(nullptr));
    for (int i = 1; i < numberOfReaders + 1; i++) {
        add(i);
        for (int j = 0; j < rand() % 5 + 1; j++) {
            int stockNumber = rand() % 1000;

            string issueDay = to_string(rand() % 31 + 1);
            if (issueDay.size() == 1) {
                issueDay = '0' + issueDay;
            }
            string issueMonth = to_string(rand() % 12 + 1);
            if (issueMonth.size() == 1) {
                issueMonth = '0' + issueMonth;
            }
            string issueYear = to_string(stoi(date.substr(6, 4))
                                         - (rand() % 2 + 1));
            string dateOfIssue = issueDay + '.';
            dateOfIssue += issueMonth + '.';
            dateOfIssue += issueYear;

            string returnDay = to_string(rand() % 31 + 1);
            if (returnDay.size() == 1) {
                returnDay = '0' + returnDay;
            }
            string returnMonth = to_string(rand() % 12 + 1);
            if (returnMonth.size() == 1) {
                returnMonth = '0' + returnMonth;
            }
            string returnYear = to_string(stoi(issueYear) + rand() % 2 + 1);
            string dateOfReturn = returnDay + '.';
            dateOfReturn += returnMonth + '.';
            dateOfReturn += returnYear;

            find(i)->data.booksList->addBook(stockNumber,
                                             dateOfIssue,
                                             dateOfReturn);
        }
    }
}

int main() {
    List library;
    unsigned int choice, stockNumber;
    string dateOfIssue, dateOfReturn;
    string date;
    cout << "Введите текущую дату (в формате DD.MM.YYYY): ";
    cin >> date;
    do {
        cout << "Выберите действие:"
                "\n1 - Случайно сгенерировать список читателей библиотеки"
                "\n2 - Добавить читателя библиотеки самому"
                "\n3 - Вывести список номеров читателей слева направо"
                "\n4 - Вывести список номеров читателей справа налево"
                "\n5 - Вывести информацию о всех читателях"
                "\n6 - Вывести информацию о конкретном читателе"
                "\n7 - Добавить сведения о взятой читателем книге"
                "\n8 - Оформить возврат определенной книги"
                "\n9 - Сформировать список книг, которые читатель не вернул в срок"
                "\n0 - выход\n";
        unsigned int readerNumber, numberOfBooks;
        cin >> choice;
        switch (choice) {
            case 1:
                unsigned int temp;
                cout << "Введите необходимое количетсво читателей: ";
                cin >> temp;
                library.randomGenerate(temp, date);
                cout << endl;
                break;
            case 2:
                cout << "Введите номер читателя: ";
                cin >> readerNumber;
                if (library.find(readerNumber)) {
                    cout << "Читатель под таким номером уже есть!\n\n";
                    break;
                }
                library.add(readerNumber);
                cout << "Введите количество книг, которое нужно добавить: ";
                cin >> numberOfBooks;
                for (int i = 0; i < numberOfBooks; i++) {
                    cout << "Введите инвентарный номер книги: ";
                    cin >> stockNumber;
                    cout << "Введите дату выдачи книги (в формате DD.MM.YYYY): ";
                    cin >> dateOfIssue;
                    cout << "Введите дату возврата книги (в формате DD.MM.YYYY): ";
                    cin >> dateOfReturn;
                    library.find(readerNumber)->data.booksList->
                            addBook(stockNumber, dateOfIssue, dateOfReturn);
                }
                cout << endl;
                break;
            case 3:
                library.printFromLeft();
                cout << endl << endl;
                break;
            case 4:
                library.printFromRight();
                cout << endl << endl;
                break;
            case 5:
                library.printAllReaders(date);
                break;
            case 6:
                cout << "Введите номер читателя: ";
                cin >> readerNumber;
                library.printReader(library.find(readerNumber), date);
                break;
            case 7:
                cout << "Введите номер читателя: ";
                cin >> readerNumber;
                cout << "Введите инвентарный номер книги: ";
                cin >> stockNumber;
                cout << "Введите дату выдачи книги (в формате DD.MM.YYYY): ";
                cin >> dateOfIssue;
                cout << "Введите дату возврата книги (в формате DD.MM.YYYY): ";
                cin >> dateOfReturn;
                library.find(readerNumber)->data.booksList->
                        addBook(stockNumber, dateOfIssue, dateOfReturn);
                break;
            case 8:
                cout << "Введите номер читателя: ";
                cin >> readerNumber;
                cout << "Введите номер книги, которую необходимо вернуть: ";
                cin >> stockNumber;
                library.find(readerNumber)->data.booksList->
                        returnBook(stockNumber);
                break;
            case 9:
                cout << "Введите номер читателя: ";
                cin >> readerNumber;
                library.printBooksNotReturned(library.find(readerNumber), date);
                break;
            case 0:
                goto end;
            default:
                break;
        }
    } while (true);
    end:
    return 0;
}

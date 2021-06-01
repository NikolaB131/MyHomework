#ifndef SiAOD_6_H
#define SiAOD_6_H
#include <string>
using namespace std;

struct Book {
    unsigned int stockNumber = 0;
    string dateOfIssue;
    string dateOfReturn;
    Book* nextBook = nullptr;
};

class BooksList {
public:
    void addBook(unsigned int stockNumber, string dateOfIssue, string dateOfReturn);
    void returnBook(unsigned int stockNumber);
    BooksList booksNotReturned(string date);
private:
    Book* first = nullptr;

    friend class List;
};

struct Data {
    ~Data();
    unsigned int readerNumber;
    BooksList* booksList = new BooksList;
};

struct Node {
    Node(unsigned int readerNumber);
    Data data;
    Node* nextNode = nullptr;
    Node* prevNode = nullptr;
};

class List {
public:
    ~List();
    void printFromLeft();
    void printFromRight();
    void printBooksNotReturned(Node* reader, string date);
    void printReader(Node* reader, string date);
    void printAllReaders(string date);
    void add(unsigned int readerNumber);
    Node* find(unsigned int readerNumber);
    void randomGenerate(unsigned int numberOfReaders, string date);
private:
    static string date;
    Node* first = nullptr;
    Node* last = nullptr;

    friend class BooksList;
};
#endif

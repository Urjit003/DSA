#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Book {
protected:
    int id;
    string name;

public:
    Book(int BookId, string BookName) : id(BookId), name(BookName) {
        cout << "Book constructor called for book id " << id << endl;
    }

    virtual ~Book() {
        cout << "Book destructor called for book id " << id << endl;
    }

    virtual void displayDetails() {
        cout << "Book ID: " << id << ", Name: " << name << endl;
    }
};

class Sales : public Book {
protected:
    int SalesCount;

public:
    Sales(int id, string name, int sales) : Book(id, name), SalesCount(sales) {
        cout << "Sales constructor called for book id " << id << endl;
    }

    ~Sales() {
        cout << "Sales destructor called for book id " << id << endl;
    }

    void DisplaySales() {
        displayDetails();
        cout << "Sales Count: " << SalesCount << endl;
    }
};

class Academics : public Book {
protected:
    int chapterCount;

public:
    Academics(int bookId, string bookName, int chapters) : Book(bookId, bookName), chapterCount(chapters) {
        cout << "Academics constructor called for book id " << id << endl;
    }

    ~Academics() {
        cout << "Academics destructor called for book id " << id << endl;
    }

    void displayAcademics() {
        displayDetails();
        cout << "Chapter Count: " << chapterCount << endl;
    }
};

class Thrillers : public Book {
protected:
    string genre;

public:
    Thrillers(int bookId, string bookName, string bookGenre) : Book(bookId, bookName), genre(bookGenre) {
        cout << "Thrillers constructor called for book id " << id << endl;
    }

    ~Thrillers() {
        cout << "Thrillers destructor called for book id " << id << endl;
    }

    void displayThrillers() {
        displayDetails();
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    vector<Book*> books;

    books.push_back(new Sales(101, "A millionaire's fastlane", 500));
    books.push_back(new Academics(201, "Introduction to Algorithms", 15));
    books.push_back(new Thrillers(301, "The Da Vinci Code", "Mystery"));

    cout << "Book details\n";
    cout << "----------------\n";

    int totalSalesBooks = 0;
    int totalAcademicsBooks = 0;
    int totalThrillersBooks = 0;

    for (auto book : books) {
        book->displayDetails();
        cout << "----------------\n";

        if (dynamic_cast<Sales*>(book) != nullptr) {
            totalSalesBooks++;
        } else if (dynamic_cast<Academics*>(book) != nullptr) {
            totalAcademicsBooks++;
        } else if (dynamic_cast<Thrillers*>(book) != nullptr) {
            totalThrillersBooks++;
        }
    }

    cout << "Total Sales Books: " << totalSalesBooks << endl;
    cout << "Total Academics Books: " << totalAcademicsBooks << endl;
    cout << "Total Thrillers Books: " << totalThrillersBooks << endl;

    // Cleanup
    for (auto book : books) {
        delete book;
    }

    return 0;
}

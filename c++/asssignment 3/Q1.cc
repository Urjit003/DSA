// 1) WAP to create base class Book having int id and char name as data members
// and respective functionality, show following types of inheritance and display
// the details of each kind of books, also calculate the total no of each type of
// books in proper format.
// Simple inheritance with derived class Sales
// Hierarchical inheritance with derived classes academics and thrillers
// Show use of constructor and destructor in above examples of inheritance.
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
using namespace std;
class Book
{
protected:
    int id;
    string name;

public:
    Book(int BookId, string BookName) : id(BookId), name(BookName) {}
    ~Book() {}
    void displayDetails()
    {
        // cout << "Book ID: " << id << ", Name: " << name << endl;
        cout << "Book ID: " << id << ", Name: " << name << endl;

    }
     void DisplyInFormat () {
       cout <<"ID|" << setw(7) << "Name|" <<setw(12) <<"Sales" << endl;
       cout << id << setw(10) << name << setw(12) ;
    }
};
class Sales : public Book
{
    int SalesCount;

public:
    Sales(int id, string name, int sales) : Book(id, name), SalesCount(sales) {}
    void DisplaySales()
    {
        displayDetails();
        std::cout << "Sales Count: " << SalesCount << std::endl;
    }
     void DisplyInFormat()  {
       cout <<"ID|" << setw(7) << "Name|" <<setw(12) <<"Sales" << endl;
       cout << id << setw(10) << setfill('*') << name << setw(12) << SalesCount;
    }
};
class Academics : public Book
{
    int chapterCount;
    public:
    Academics(int bookId, string bookName, int chapters) : Book(bookId, bookName), chapterCount(chapters)
    {
        cout << "Academics constructor called for book id " << id << endl;
    }
    void displayAcademics()
    {
        displayDetails();
        std::cout << "Chapter Count: " << chapterCount << std::endl;
    }
  
};
class Thrillers : public Book
{
private:
    string genre;

public:
    Thrillers(int bookId, string bookName, string bookGenre) : Book(bookId, bookName)
    {
        this->genre = bookGenre;
        cout << "Thrillers constructor called for book id " << id << std::endl;
    }

    void displayThrillers()
    {
        displayDetails();
        std::cout << "Genre: " << genre << std::endl;
    }
};
int main()
{
    // Sales *salesbook = new Sales(101, "A millionaire's fastlane", 500);
    // salesbook->DisplyInFormat();
    vector<Book*> books;
    books.push_back(new Sales(101, "A millionaire's fastlane", 500));

    cout << "Book details\n";
    for(auto book : books) {
        book->DisplyInFormat();
    }
    return 0;
}
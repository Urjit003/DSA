// 2. WAP to define a class Date with properties int month; int day; int year;
// Overload the + operator [a+b] (a is of date type and b is an integer – No of
// days to add in date), use the assumption that all years have 360 days and
// months 30 days.

#include <iostream>

class Date {
private:
    int month, day, year;

public:
    // Constructor to initialize the date
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    // Overloading the + operator to add days to a date
    Date operator+(int days) const {
        Date result = *this;  // Create a copy of the current date
        result.day += days;   // Add the specified number of days

        // Adjust the date considering months and years
        while (result.day > 30) {
            result.day -= 30;
            result.month++;

            if (result.month > 12) {
                result.month = 1;
                result.year++;
            }
        }

      
        return result;
    }

    // Display the date
    void display() const {
        std::cout << "Date: " << month << "/" << day << "/" << year << std::endl;
    }
};

int main() {
    // Create a Date object
    Date currentDate(1, 22, 2024);

    // Display the current date
    std::cout << "Current ";
    currentDate.display();

    // Add 45 days to the current date using the + operator
    Date newDate = currentDate + 5;

    // Display the updated date
    std::cout << "Updated ";
    newDate.display();

    return 0;
}

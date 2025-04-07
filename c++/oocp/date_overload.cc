#include <iostream>

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructor to initialize the Date object
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    // Overloading + operator to add days to a Date
    Date operator+(int days) {
        int totalDays = year * 360 + month * 30 + day + days;
        
        // Calculate new values for year, month, and day
        int newYear = totalDays / 360;
        int remainingDays = totalDays % 360;
        int newMonth = remainingDays / 30;
        int newDay = remainingDays % 30;

        return Date(newMonth, newDay, newYear);
    }

    // Function to display the Date
    void display() {
        std::cout << "Date: " << month << "/" << day << "/" << year << std::endl;
    }
};

int main() {
    // Create a Date object
    Date currentDate(02, 10, 2024);

    // Display current date
    std::cout << "Current ";
    currentDate.display();

    // Add 45 days to the current date
    Date newDate = currentDate + 45;

    // Display the updated date
    std::cout << "After adding 45 days ";
    newDate.display();

    return 0;
}

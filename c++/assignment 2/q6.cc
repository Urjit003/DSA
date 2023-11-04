#include <iostream>
#include <stdlib.h>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    // Overloading + operator for addition of Time and integer
    Time operator+(int seconds) const {
        Time temp(hour, minute, second + seconds);
        if (temp.second >= 60) {
            temp.second -= 60;
            temp.minute++;
        }
        return temp;
    }

    // Overloading - operator for subtraction of integer from Time
    Time operator-(int seconds) const {
        Time temp(hour, minute, second - seconds);
        if (temp.second < 0) {
            temp.second += 60;
            temp.minute--;
        }
        return temp;
    }

    // Overloading assignment operator
    Time& operator=(const Time& other) {
        if (this != &other) {
            hour = other.hour;
            minute = other.minute;
            second = other.second;
        }
        return *this;
    }

    // Overloading comparison operators
    bool operator<(const Time& other) const {
        if (hour < other.hour) return true;
        if (hour == other.hour && minute < other.minute) return true;
        return (hour == other.hour && minute == other.minute && second < other.second);
    }

    bool operator<=(const Time& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const Time& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Time& other) const {
        return !(*this < other);
    }

    // Overloading pre-increment operator
    Time& operator++() {
        second++;
        if (second >= 60) {
            second -= 60;
            minute++;
            if (minute >= 60) {
                minute -= 60;
                hour++;
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
        return *this;
    }

    // Overloading post-increment operator
    Time operator++(int) {
        Time temp(*this);
        ++(*this);
        return temp;
    }

    // Overloading pre-decrement operator
    Time& operator--() {
        second--;
        if (second < 0) {
            second += 60;
            minute--;
            if (minute < 0) {
                minute += 60;
                hour--;
                if (hour < 0) {
                    hour = 23;
                }
            }
        }
        return *this;
    }

    // Overloading post-decrement operator
    Time operator--(int) {
        Time temp(*this);
        --(*this);
        return temp;
    }

    // Display function
    void display() const {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    Time t1(10, 45, 30);
    Time t2 = t1 + 120; // Adding 120 seconds
    Time t3 = t2 - 60;  // Subtracting 60 seconds

    cout << "Original Time: ";
    t1.display();
    cout << "Time after adding 120 seconds: ";
    t2.display();
    cout << "Time after subtracting 60 seconds: ";
    t3.display();

    Time t4(12, 30, 15);
    Time t5(10, 15, 45);
    cout << "Comparison Result: " << (t4 >= t5 ? "t4 is greater than or equal to t5" : "t4 is smaller than t5") << endl;

    cout << "Pre-increment: ";
    ++t1;
    t1.display();
    cout << "Post-increment: ";
    t1++;
    t1.display();
    cout << "Pre-decrement: ";
    --t1;
    t1.display();
    cout << "Post-decrement: ";
    t1--;
    t1.display();

    return 0;
}

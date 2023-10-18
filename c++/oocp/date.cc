#include <iostream>
#include <stdlib.h>
using namespace std;
class Date
{
    int day, month, year;

public:
    Date()
    {
        do
        {
            cout << "Enter day/month/year: ";
            cin >> day >> month >> year;
        } while (!isValidDate(day , month , year));
    }

    Date(int d, int m, int y)
    {
        if (isValidDate(d,m,y))
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            cout << "INVALID date entered , setting today's date \n";
            day = 18 , month = 10 , year = 2023;
            // You might want to handle this case, such as setting default values or asking the user for valid input.
        }
    }
    bool isValidDate(int d, int m, int y) const {
        if (m >= 1 && m <= 12) {
            if ((d >= 1 && d <= 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)) ||
                (d >= 1 && d <= 30 && (m == 4 || m == 6 || m == 9 || m == 11)) ||
                (d >= 1 && d <= 29 && m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) ||
                (d >= 1 && d <= 28 && m == 2 && !((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))) {
                return true;
            }
        }
        return false;
    }
    void Display()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
    void add()
    {
        int x;
        cout << "Enter how many days you wish to add" << endl;
        cin >> x;
        day += x;
        // 30 days addted to feb
        while (day > GetDaysinMonth())
        {
            // 8 = 20 - 28
            day = day - GetDaysinMonth();
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }

    int GetDaysinMonth()
    {
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                return 29;
            }

            else
            {
                return 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            return 30;
        }
        else
        {
            return 31;
        }
    }
};
int main()
{
    Date d;
    d.Display();
    d.add();
    d.Display();
    return 0;
}
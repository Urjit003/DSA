// Marie invented a Time Machine and wants to test it by time-traveling to visit Russia on the Day of the Programmer (the 256th day of the year) during a year in the inclusive range from 1700 to 2700.

// From 1700 to 1917, Russia's official calendar was the Julian calendar; since 1919 they used the Gregorian calendar system. The transition from the Julian to Gregorian calendar system occurred in 1918, when the next day after January 31st was February 14th. This means that in 1918, February 14th was the 32nd day of the year in Russia.

// In both calendar systems, February is the only month with a variable amount of days; it has 29 days during a leap year, and 28 days during all other years. In the Julian calendar, leap years are divisible by 4; in the Gregorian calendar, leap years are either of the following:

// Divisible by 400.
// Divisible by 4 and not divisible by 100.
// Given a year, , find the date of the 256th day of that year according to the official Russian calendar during that year. Then print it in the format dd.mm.yyyy, where dd is the two-digit day, mm is the two-digit month, and yyyy is .

// For example, the given  = 1984. 1984 is divisible by 4, so it is a leap year. The 256th day of a leap year after 1918 is September 12, so the answer is .

// BEFORE 1917 -> leap year % 4 == 0
// Divisible by 400.
// Divisible by 4 and not divisible by 100.
// AFRTER 1917 (GREGORIAN CALENDER) ->( leap year % 400 == 0) || (year%4 == 0 && year%100 != 0)
#include <bits/stdc++.h>
#define YEAR_OF_CALENDER_CHANGE_FROM_JULIAN_TO_GREGORIAN 1918
#define DAY_OF_PROGRAMMER 256
using namespace std;
string dayOfProgrammer(int year)
{
    int remaining_days = 0;
    if (year <= 1700 || year >= 2700)
    {
        exit(true);
    }
    // bool isLeapYearJulian = ;
    // bool isLeapYearGregorian =;
    bool LeapYear = false;
    if (year < YEAR_OF_CALENDER_CHANGE_FROM_JULIAN_TO_GREGORIAN) // 1800 < 1919
    {
        // JULIAN CALENDER
        LeapYear = (year % 4 == 0);
    }
    else
    {
        // GREGORIAN CALENDER
        LeapYear = (year % 400 == 0) || (year % 4 == 0 && !(year % 100 == 0));
    }
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string month[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    int days = 0;

    if (LeapYear)
    {
        months[1] = 29;
    }
    for (int i = 0; i < 12; i++)
    {
        days += months[i];
        if(i ==7)
            break;
       
    }
    if(year == 1918) { LeapYear ? days-=14 : days-=13;}
    // cout << "DAYS : " << days << " | ";
    remaining_days = DAY_OF_PROGRAMMER - days;
    // 256 - 244
    string formated_year = to_string(remaining_days) + "." + (month[8] == "september" ? "09" : "") + "." + to_string(year);
    return formated_year;
}

int main()
{
    cout << (dayOfProgrammer(2016));

    return 0;
}
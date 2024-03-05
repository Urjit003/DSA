#include <iostream>
using namespace std;

class Time {
    int hours, minutes, seconds;

public:
    Time() {
        do {
            cout << "Enter hours/minutes/seconds: ";
            cin >> hours >> minutes >> seconds;
        } while (!isValidTime(hours, minutes, seconds));
    }

    bool isValidTime(int h, int m, int s) const {
        return (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60);
    }

    void Display() {
        cout << hours << " hours " << minutes << " minutes " << seconds << " seconds" << endl;
    }

    void add() {
        int x;
        cout << "Enter how many minutes you wish to add: ";
        cin >> x;
        minutes += x;

        while (minutes >= 60) {
            minutes -= 60;
            hours++;
            if (hours >= 24) {
                hours = 0;
            }
        }
    }
};

int main() {
    Time t;
    t.Display();
    t.add();
    t.Display();
    return 0;
}

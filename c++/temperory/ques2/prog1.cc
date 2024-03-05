#include <iostream>

class Time {
private:
    int hours, minutes, seconds;

public:
    // Constructor to initialize the time
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Function to add seconds to the time
    void addSeconds(int additionalSeconds) {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds + additionalSeconds;

        // Update hours, minutes, and seconds based on total seconds
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
    }

    // Display the time
    void display() const {
        std::cout << "Time: " << hours << " hours " << minutes << " minutes " << seconds << " seconds" << std::endl;
    }
};

int main() {
    // Create a Time object
    Time currentTime(2, 30, 45);

    // Display the current time
    std::cout << "Current ";
    currentTime.display();

    // Read additional seconds from the user
    int additionalSeconds;
    std::cout << "Enter additional seconds: ";
    std::cin >> additionalSeconds;

    // Add the specified seconds to the time
    currentTime.addSeconds(additionalSeconds);

    // Display the updated time
    std::cout << "Updated ";
    currentTime.display();

    return 0;
}

#include <iostream>
#include <iomanip>

// User-defined manipulator function
std::ostream &prefix(std::ostream &os)
{
    // Add a prefix to the output
    os << "GANG GANG !";
    return os;
}

int main()
{
    // int number = 42;

    // // Using the user-defined manipulator
    // std::cout << prefix << "This is a message with a prefix." << std::endl;

    // // Outputting a number with the prefix manipulator
    // std::cout << prefix << "Number: " << number << std::endl;
    // std::cout << std::setw(20) << "Hello" << std::endl;
    // std::cout << std::setfill('_') << std::setw(8) << 42 << std::endl;
    // std::cout << std::setiosflags(std::ios::fixed) << 3.14 << std::endl;
    // std::cout << std::setprecision(1) << 3.14159;

      std::cout.width(10);
    std::cout << "Hello" << std::endl;
    
    return 0;
}

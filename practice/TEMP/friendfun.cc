#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;
class employee
{
    static int EmpIdCounter;
    int EmpId;
    string name, designation;
    string DeptChoice[3] = {"Finance", "IT", "HR"};
    string Dept;

public:
    employee(string name, string designation) : name(name), designation(designation)
    {
        EmpId = ++EmpIdCounter;
        int choice;
        do
        {

            cout << "dept for " << name << " " << endl;
            cout << "0 for finance , 1 for IT , 2 for HR" << endl;
            cin >> choice;

            if (choice >= 0 && choice < 3)
            {
                this->Dept = DeptChoice[choice];
            }

        } while (choice < 0 || choice >= 3);
    }
   void getHeader() {
        std::cout << "\033[1m" << std::setw(20) << "Name"
                  << std::setw(15) << "EmpId"
                  << std::setw(20) << "Designation"
                  << std::setw(20) << "Department"
                  << "\033[0m\n";

        std::cout << "\033[1m" << std::setfill('-') << std::setw(75) << "" << "\033[0m\n";
        std::cout << std::setfill(' '); // Reset fill character
    }

    void get() {
        std::cout << "\033[1m" << std::setw(20) << name
                  << std::setw(15) << EmpId
                  << std::setw(20) << designation
                  << std::setw(20) << Dept << "\033[0m\n";
    }
    friend void display(employee a1);
};
int employee::EmpIdCounter = 0;

void display(employee a1)
{
    a1.get();
}
int main()
{
    employee employees[3] = {
        {"Urjit", "developer"},
        {"Hardik", "Manager"},
        {"kishore", "Gamer tester"}};
    
        employees.getHeader();
    for (int i = 0; i < 3; ++i)
    {
        employees[i].get();
    }
    return 0;
}
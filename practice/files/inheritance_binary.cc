#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class Student
{
public:
    int age, rollno;
    char *name;

    Student(int age, char *name, int roll);
    ~Student();
};

Student::Student(int age, char *name, int roll)
{
    this->age = age;
    this->name = name;
    this->rollno = roll;
}

Student::~Student()
{
}

int main()
{
    fstream fs("abc.txt", ios::out | ios::binary);

    Student s1(20, "Urjit", 07);
    fs.write(reinterpret_cast<char *>(&s1), sizeof(s1));
    fs.read(reinterpret_cast<char *>(&s1), sizeof(s1));
    cout << s1.name;
    fs.close();
    return 0;
}
#include <iostream>
#include <stdlib.h>
using namespace std;
class Student
{
public:
    int id;
    string Name;
    float per;
};
int main()
{
    Student s1[5];
    for (int i = 0; i < 5; i++)
    {
        s1->id = i + 1;
        cout << "Enter name of student " << i + 1;
        cin >> s1->Name[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << s1->id <<s1->Name << endl;
    }
    
    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class employee
{
    int EmpNo;
    string Name;
    string DeptName;
    string Designation;

public:
    void Init(int TempNo, string TempName, string TempDept, string TempDesi)
    {
        EmpNo = TempNo;
        Name = TempName;
        DeptName = TempDept;
        Designation = TempDesi;
    }

    void DisplayDetails()
    {
        cout << "Details of employee number " << EmpNo << "\n";
        cout << "Name is " << Name << "\n";
        cout << "Department is " << DeptName << "\n";
        cout << "Designation is " << Designation << "\n";
    }
    /* Now following standalone function is granted access to private
    variables of this class */
    friend void ListDeptWise(employee[]);
};

void ListDeptWise(employee UniEmp[])
{
    string TempDeptName;
    cout << "Please Enter the Department of the University : ";
    cin >> TempDeptName;
    cout << "\n";

    for (int i = 0; i < 10; ++i)
    {
        if (UniEmp[i].DeptName == TempDeptName)
        /* The access of private variable DeptName is not allowed
        if ListDeptWise is not friend */
        {
            UniEmp[i].DisplayDetails();
        }
    }
}
int main()
{

    employee UniEmployee[10];
    UniEmployee[1].Init(1, "Robin", "Exam", "Professor");
    UniEmployee[2].Init(2, "Bob", "Marksheet", "Clerk"),
        UniEmployee[3].Init(3, "Leena", "Accounts", "HeadClerk"),
        UniEmployee[4].Init(4, "Seema", "Exam", "Clerk"),
        UniEmployee[5].Init(5, "Rohit", "Accounts", "CAO"),
        UniEmployee[6].Init(6, "Vibha", "Exam", "Informer"),
        UniEmployee[7].Init(7, "Kesar", "Exam", "Sleeper"),
        UniEmployee[8].Init(8, "Michel", "Exam", "Examiner"),
        UniEmployee[9].Init(9, "Hari", "Marksheet", "Repeater"),
        UniEmployee[0].Init(10, "Meena", "Accounts", "Clerk");

    ListDeptWise(UniEmployee);

    return -1;
}
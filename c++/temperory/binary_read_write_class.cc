#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

class employee
{
public:
    int id;
    char name[300], addr[500];
    employee() {}
    employee(int _id, string _name, string _addr)
    {
        id = _id;
        strcpy(name, _name.c_str());
        strcpy(addr, _addr.c_str());
    }

    void info()
    {
        cout << "ID : " << id << "\tName: " << name << "\tAddress : " << addr << endl;
    }
};
void create(employee obj)
{
    ofstream file("details.txt", ios::app | ios::binary);
    file.write(reinterpret_cast<char *>(&obj), sizeof(obj));
    file.close();
}
void read()
{
    ifstream file("details.txt", ios::binary);
    employee obj;

    while (file.read(reinterpret_cast<char *>(&obj), sizeof(obj)))
    {
        obj.info();
    }
}
bool update(int id, string addr)
{
    // search
    bool found = 0;
    fstream file("details.txt", ios::in | ios ::out | ios::binary);

    employee obj;

    while (file.read(reinterpret_cast<char *>(&obj), sizeof(obj)))
    {
        if (obj.id == id)
        {
            found == 1;

            strcpy(obj.addr, addr.c_str());

            file.seekp(file.tellg() - sizeof(obj) , ios::beg);
            file.write(reinterpret_cast<char *>(&obj), sizeof(obj));
        }
    }
}
int main()
{
    employee a(1, "Urjit", "abc");
    employee b(2, "Urjit1", "abcd");

    create(a);
    create(b);


    read();

    cout << update(2,"chandkheda");
    read();
    return 0;
}
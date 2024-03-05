#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void createFile()
{
    fstream fs;
    fs.open("hello.txt", ios::app);
    string line;
    cout << "$END$ to end " << endl;
    while (cin >> line && line != "$END$")
    {
        fs << line << " .";
    }
    fs.close();
}
void readfile()
{
    fstream fs;
    fs.open("hello.txt", ios::in);
    string line;
    cout << " \" ";
    while (getline(fs, line))
    {
        cout << line << " ";
    }
    cout << " \" ";

    fs.close();
}
int main()
{
    createFile();
    readfile();
    return 0;
}
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main (){
    fstream fs("Q4.cc",ios::in);
    ofstream of("copy_of_Q4.cc");
    string line ;
    while (getline(fs,line))
    {
        cout << line <<endl;
        of << line << endl;
    }
    of.close();
    fs.close();
return 0;
}
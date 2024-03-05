#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    string name;
    fstream fs("read.txt" , ios::in) ;
    string line ;

    fs.seekg(0);
    getline(fs , line);

    cout << line;
    return 0;
}
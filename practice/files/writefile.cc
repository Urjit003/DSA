#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int main (){
    fstream fs ("writefile.txt" , ios::app) ;

    // fs << "HELLO WORLD" << " ";
    cout << fs.tellp();
    fs.close();
return 0;
}
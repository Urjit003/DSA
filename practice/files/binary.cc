#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int main (){
    fstream fs("abc.txt" ,ios::out  | ios::binary );
     
    int p  = 10;
    // fs.read( (char *)&p,sizeof(p));
    fs.write( reinterpret_cast<char*>(&p), sizeof(p));
    cout << p << endl;
    fs.read( reinterpret_cast<char*>(&p), sizeof(p));
    cout << p;
    fs.close();
return 0;
}
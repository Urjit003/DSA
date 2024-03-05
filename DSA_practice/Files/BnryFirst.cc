#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int main (){
fstream file("abc1.txt",ios::binary |ios::out | ios::in);
    int p = 100;
    file.write(reinterpret_cast<char *>(&p) , sizeof(p));

    char buffer[5];
    file.read(buffer,sizeof(buffer));

    if(file) {
        cout.write(buffer,file.gcount());
    }

    file.close();
    file.clear();
return 0;
}
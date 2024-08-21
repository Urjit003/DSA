#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
void print (string s, int  n) {
    cout << s<< n << "\n";
    if (n == 0) {
        return;
    }
    print(s,--n);
}
int main (){
print("yo",10);
return 0;
}
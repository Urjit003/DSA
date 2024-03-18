#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
void print (int n) {
    cout << "HELLO WORLD " << n << "\n";
    if (n == 0) {
        return;
    }
    print(--n);
}
int main (){
print(10);
return 0;
}
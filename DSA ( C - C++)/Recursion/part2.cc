#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
void fun (int n ) {
    if (n == 0) 
        return;
    cout << n  << endl;
    fun(--n);
}
int main (){
fun(5);
// 5 4 3 2 1
// 5 4 3 2 1 0
// INF LOOP
return 0;
}
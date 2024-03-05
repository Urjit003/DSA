#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
int fib(int n) {
    if(n<=2) return 1;
    return fib(n-1) + fib(n-2);
}
int main (){
    int n = fib(58);
    std::cout << "3rd in the fibbonaci is " << n <<std::endl;
return 0;
}
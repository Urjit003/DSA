#include<iostream>
#include<stdlib.h>
using namespace std;

template <typename T> T sum(T a , T b) {
    return a +b ;
}

int main (){
    cout << sum<float>(10.10,20);
return 0;
}
#include<iostream>
#include<stdlib.h>
using namespace std;
class Base {
    int x;
    public:
    void Setx(int val) { x = val; } 
    inline void Getx() { cout << x <<endl;}
};
class Derived :private Base {
    public:
    Derived (int val) {
        Setx(val);
        Getx();
    } 
};
int main (){
Derived v1(10);
return 0;
}
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
class A {
    public:
    int value ;
    A(int x) : value(x) {}
    A() {}

    int GetVal() {return this->value;}
};

int main (){
        A a1(10),*ptra1 ;
        ptra1 = &a1;

        // a1->value = 10 ;
        cout << a1.GetVal();
        cout << ptra1->GetVal();
return 0;
}
#include<iostream>
#include<stdlib.h>
using namespace std;
class abc {
    int x;
    public:
    abc(int x) : x(x) {}
    abc operator+(const abc& obj) const{
        abc temp(x);
        temp.x= x + obj.x ;
        return temp;
    }
    abc operator-(const abc& obj) const{
        abc temp(x);
        temp.x= x - obj.x ;
        return temp;
    }
    void display() const{
        cout << x;
    }
};
int main (){
    abc a1(10);
    abc a2(20);
    abc a3 (10);
    abc res =a2 - a1-10;
    res.display();

return 0;
}
#include<iostream>
#include<stdlib.h>
using namespace std;
class abc {
    int x,y;
    public:
    abc(int a1 , int a2) : y(a2) , x(a1) {}
    void display() {
        cout << x << " " << y ;
    }
    abc operator+ (abc &obj) {
        abc temp(x,y);
        temp.x = x + obj.x;
        temp.y = y + obj.y;
        return temp;
    }
};
int main (){
abc x1(10,20);
abc x2(15,25);
abc x3 = x1 + x2;
x3.display();

return 0;
}
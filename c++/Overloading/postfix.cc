#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
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
    abc operator++() {
        x++;
        return (x);
    }
    abc operator++(int) {
        x++;
        return (x);
    }
    void display() const{
        cout << x << endl;

    }
};
int main (){
    abc a(10);
    a.display();
    ++a;
    a.display();
    a++;
    a.display();
return 0;
}
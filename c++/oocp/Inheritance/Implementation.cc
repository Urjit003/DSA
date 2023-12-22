#include<iostream>
#include<stdlib.h>
using namespace std;
class Base {
    
    public: 
    void Greet () {
       cout << "Greetings from base class \n"; 
    }
}; 
class Derived :  public Base {
    public :
    Derived() {
        cout << "Greetings from Derived class \n" ;
        Greet ();
    }
} ;
int main (){
Derived s1;
return 0;
}

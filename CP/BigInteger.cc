#include<bits/stdc++.h>
class BigInt {
    string digits ;

    public :
    BigInt(string &);
    BigInt(int &);
    // OPERATORS OVERLOADING 
    friend ostream &operator<<(ostream &,BigInt &);
};
using namespace std;
int main (){
    BigInt n("25") ;

    
return 0;
}
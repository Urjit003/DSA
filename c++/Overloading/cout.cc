#include<iostream>
#include<stdlib.h>
using namespace std;
class Urjit
{
private:
    string address;
    int HouseNo;
public:
    Urjit(string addr , int no);
    friend ostream& operator<<(ostream& COUT,Urjit& obj);
};

Urjit::Urjit(string addr , int no)
{
    this->address = addr;
    this->HouseNo = no;
}
ostream& operator << (ostream& COUT,Urjit& obj) {
    COUT << "address : " << obj.address << endl;
    COUT << "House no : "<< obj.HouseNo << endl;
    return COUT;
}
int main (){
    Urjit a1 = Urjit ("Neelkahth",7);
    cout << a1;
return 0;
}
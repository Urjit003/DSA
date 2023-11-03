#include<iostream>
#include<stdlib.h>
using namespace std;
class Urjit
{
private:
    string address;
    int HouseNo;
public:
    // Urjit(string addr , int no);
    friend ostream& operator<<(ostream& OUTPUT,Urjit& obj);
    friend istream& operator>>(istream& INPUT,Urjit& obj);
};

// Urjit::Urjit(string addr , int no)
// {
//     this->address = addr;
//     this->HouseNo = no;
// }
ostream& operator << (ostream& OUTPUT,Urjit& obj) {
    OUTPUT << "address : " << obj.address << endl;
    OUTPUT << "House no : "<< obj.HouseNo << endl;
    return OUTPUT;
}
istream& operator >>(istream& INPUT,Urjit& obj) {
    INPUT >> obj.address >> obj.HouseNo ;
    return INPUT;
}
int main (){
    Urjit a1 ;
    cin >> a1; 
    cout << a1 ;
return 0;
}
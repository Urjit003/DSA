#include<iostream>
#include<stdlib.h>
using namespace std;
string RevString(string str) {
     int length=0 ;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length ++;
    }
    string returnstring;
    for (int i = length-1; i >= 0; i--)
    {
        // cout <<  "[" <<str[i] << "]";
        str[length + length - 1 - i] = str[i];
    }
    return str;
    
}
int main (){

string Name = "Urjit";
cout << Name << endl;
Name = RevString(Name);    
cout << Name;
return 0;
}
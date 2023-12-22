#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main (){
    ofstream of;
    of.open("EXPL.txt");
    of << "AYO WAZUP NIGGAS\nYOYYO";
    of.close();
return 0;
}

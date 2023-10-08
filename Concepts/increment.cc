#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // int a = 5 , b=0;
    // b = 5 + a++ + a;
    //    6     6   7
    // b = ++a + a++ + a;
    // b = ++a;
    // b = b + a++;
    // b = b + a;
    // cout <<"b = " << b;
    char array[5] = {'a', 'b', 'c', 'd', 'e'};
    int i = 0;
    // cout <<"" << array[0];
    cout << "\n"
         << array[++i];
    cout << "\n"
         << array[i++];
    cout << "\n"
         << array[i];

    return 0;
}
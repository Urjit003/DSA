#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int a = 10,b=20;
    int *aPTR = &a, *bPTR= &b;

    cout << *aPTR + *bPTR << endl;

    return 0;
}
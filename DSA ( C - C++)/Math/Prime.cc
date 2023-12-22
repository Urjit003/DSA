#include <iostream>
#include <stdlib.h>
using namespace std;

bool PrimeOrNot (int val) {
    if(val <= 1) {
        return false ;
    }
    int k = 2 ;
    while (k*k <= val)
    {
        if(val%k == 0) {
            return false;
        }
        k ++;
    }
    return true;
}
int main()
{
    for (int i = 0; i < 20; i++)
    {
        printf("%d is %s\n",i,PrimeOrNot(i)? "prime" : "not prime");
    }
    
    return 0;
}
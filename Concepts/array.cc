#include <iostream>
#include <stdlib.h>
using namespace std;

long long int sum(int range)
{

    long long int sum = 0;
    for (long long int i = 0; i < range; i++)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    cout << sum(12);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int factorial(int n);
int factorial(int n)
{
    if (n >= 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
int main()
{
    printf("%d\n", factorial(5));
    return 0;
}
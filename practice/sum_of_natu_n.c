#include <stdio.h>
#include <stdlib.h>
int sum(int size)
{
    long long int result = 0;
    for (int i = 1; i <= size; i++)
    {
        result += i;
    }
    return result;
}
long long int bettersum(long long int n){
    return ((n*n +n)/2);
}   
int main()
{
    int a = bettersum(10460265);
    printf("%d \n",a);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int *dosum(int *a, int *b)
{
    int *c = *a + *b;
    return (c);
}
int main()
{
    int a = 10, b = 50;
    int *c = dosum(&a, &b);
    printf("%d", c);
    return 0;
}
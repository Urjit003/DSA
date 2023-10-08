#include <stdio.h>
#include <stdlib.h>
void print(int n)
{
    if (n == 5)
    {
        printf("%d \n", n);
        return;
    }

    printf("%d \n", n);
    print(n + 1);
}
int main()
{
    print(1);
    return 0;
}
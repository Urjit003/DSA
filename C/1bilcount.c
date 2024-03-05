#include <stdio.h>
#include <stdlib.h>
int main()
{
    size_t a = 0;
    while (a < 1000000000)
    {
        a++;
    }
    printf("%d", a);

    return 0;
}
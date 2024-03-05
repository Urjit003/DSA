#include <stdio.h>
#include <stdlib.h>
int main()
{
    // example of bitwise operation
    int a = 6;     // 6  =  00000110
    int b = 12;    // 12 =  00001100
    int c = a & b; //  0   = 00000000
    printf("%d\n", c);

    // c   = 00001110
    c = a | b;
    printf("%d\n", c);

    // c   = 00001010
    c = a ^ b;
    printf("%d\n", c);

    // a        =  00000110
    // a << 1    = 00001100
    c = a << 1;
    printf("%d\n", c);

    c =  a >> 3;
    c = (float)c;
    printf("%d\n", c);
    return 0;
}
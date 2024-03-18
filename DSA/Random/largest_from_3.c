#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int LargestFromThree(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    else if (b > a && b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
}
int main()
{
    int a = 101, b = 12231313, c = 1200;
    int res = LargestFromThree(a, b, c);
    // char var ;
    // if (res == a )
    // {
    //     var ='a';
    // }else if (res == b)
    // {
    //     var='b';
    // }   else if (res ==c)
    // {
    //     var = 'c';
    // }

    printf("%c is the largest [%d] \n", (res == a) ? 'a' : (res == b) ? 'b'
                                                                      : 'c',
           LargestFromThree(a, b, c));
    return 0;
}
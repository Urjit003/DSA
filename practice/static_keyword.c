#include <stdio.h>
#include <stdlib.h>
void hey () {
    int a = 10;
    static int b = 10 ;
    a += 5;
    b += 5;
    printf("a = %d , b = %d\n",a,b);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        hey();
    }
    
    return 0;
}
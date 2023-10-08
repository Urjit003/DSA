#include <stdio.h>
#include <stdlib.h>
int starpattern(int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0;  j<=i; j++)
        {
            printf("* ");
            /* code */
        }
        printf("\n");
    }
    
}
int main()
{
    starpattern(5);
    return 0;
}
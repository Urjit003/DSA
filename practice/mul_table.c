#include <stdio.h>
#include <stdlib.h>
int multable(int size,int length)
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            printf("%dx%d=%d\n", i, j, i * j);
        }
        printf("\n");
    }
}
int main()
{
    multable(20,10);
    return 0;
}
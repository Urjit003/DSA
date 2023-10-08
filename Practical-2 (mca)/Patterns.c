#include <stdio.h>
#include <stdlib.h>
void RightHalfPYM(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            printf("* ");
        }

        printf("\n");
    }
}
void LeftHalfPYM(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int space = n; space >= row; space--)
        {
            printf(" ");
        }
        for (int col = 1; col <= row; col++)
        {
            printf("*");
        }

        printf("\n");
    }
}
void Pyramid(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= 2 * n - 1; col++)
        {
            if (col >= n - (row - 1) && col <= n + (row - 1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main()
{
    Pyramid(5);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i = 1;
    int num;
    do {
        printf("Enter a positive integer number\n");
        scanf("%d",&num);

        if(num <= 0 ) {
            printf("INVALID\n");
        }
    }while(num<=10);
    return 0;
}
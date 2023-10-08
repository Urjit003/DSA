#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    do {
        /* code here */ 
        printf("Enter num < 10 \n");
        scanf("%d",&num);
    } while(num > 10);
    return 0;
}
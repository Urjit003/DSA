#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap (int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a = 10, b = 20;
    swap(&a,&b);
    printf("%d\t%d \n",a,b);
    
    return 0;
}
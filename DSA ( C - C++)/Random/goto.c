#include <stdio.h>
#include <stdlib.h>

int main() {
    int a ;
    step1:
    printf("\nEnter the value of A , should be less than 10: ");
    scanf ("%d",&a);
    while (a>10) {
        printf("%d is greater than 10",a);
        goto step1;
    }
return 0 ;
}

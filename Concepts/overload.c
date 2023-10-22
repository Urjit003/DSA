#include <stdio.h>
#include <stdlib.h>
int sum(int a , int b ) {
    return a +b ;
}
float sum (float a , float b ) {
    return a +b ;
}
int main() {
printf("%d \n",sum(10,20))  ;
printf("%d \n",sum(10.10,20.10))  ;

return 0 ;
}
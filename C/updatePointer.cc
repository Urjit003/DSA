#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

void update(int *a,int *b) {
    *a+=*b;
    *b=abs(a - b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
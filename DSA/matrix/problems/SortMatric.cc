// Input : mat[][] = {      {5, 4, 7},
//                          {1, 3, 8},
//                          {2, 9, 6} }
// Output :     1 2 3
//              4 5 6
//              7 8 9
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
void swap(int *a , int *b) {
    int temp;
    temp =*a ;
    *a=*b;
    *b= temp;
}
int main()
{
    int arr[3][3] = {{5, 4, 7},
                     {1, 3, 8},
                     {2, 9, 6}};
 
    
    return 0;
}
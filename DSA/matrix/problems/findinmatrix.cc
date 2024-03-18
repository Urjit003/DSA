#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    // row X column
    int arr[2][3]= {
        {1,2,3},
        {4,5,6}
    };
    int found = 0 , element = 5,x,y;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(element == arr[i][j]){
                found =1;
                x= i;
                y =j;
            }
        }
    }
    if(found) {
        cout << "Element found at " << x <<""<<y ;
    }else {
        cout << "Element not found" ;

    }
    return 0;
}
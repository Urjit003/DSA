#include <iostream>
#include <stdlib.h>
#define loop(arr, a, b)          \
    for (int i = a; i <= b; i++) \
    {                            \
        cout << arr[i] << " " ;   \
    }
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    loop(arr,0,sizeof(arr)/sizeof(int)-1)
    return 0;
}
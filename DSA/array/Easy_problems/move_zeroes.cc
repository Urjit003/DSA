#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define vi vector<int>
#define pb push_back
using namespace std;
vector<int> PushZeroesBrute(vector<int>& arr) {
    vi result ;
    // adding all non-zero elements to temp vector 
    for(int n : arr) {
        if( n != 0 ) {
            result.pb(n) ;
        }
    }
    int NonZero = arr.size() - result.size() ; 
    for(int i =  0 ; i < NonZero ; ++i) {
        result.pb(0) ;
    }
    arr = result ;
    return arr;
}
vector<int> PushZeroesOriginal(vector<int> &arr, int size) {
    
    int n = (int)arr.size();
    int j = {0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i]!=0)
        {
            arr[j++] = arr[i];
            // j++;
        }
    }

    for (j; j <n ;j ++) {
            arr[j] = 0 ;
    }    
    return arr;
}
vi PushZeroesOptimal(vi& arr) {
int n = arr.size() ;
int NonZeroPos = 0;
for (int i = 0; i < n; i++)
{
    if(arr[i] != 0) {
        swap(arr[NonZeroPos++] , arr[i]) ;
        // NonZeroPos ++; 
    }   
}
return arr; 
}
int main() {
    // Your code here
    vector<int> arr = {0, 1, 0, 3, 12};
    int size = arr.size();
    vector<int> arrN = PushZeroesOptimal(arr);
    for (auto i = arrN.begin(); i != arrN.end(); i++)
    {
        cout << *i << " ";
    }

}
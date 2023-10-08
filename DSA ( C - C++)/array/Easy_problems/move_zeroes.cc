#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
vector<int> PushZeroes(vector<int> &arr, int size) {
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
int main() {
    // Your code here
    vector<int> arr = {1,2,3,0,2,4,0,0,3,2,4,50,0,11,0,66,0};
    int size = arr.size();
    vector<int> arrN = PushZeroes(arr,size);
    for (auto i = arrN.begin(); i != arrN.end(); i++)
    {
        cout << *i << " ";
    }

}
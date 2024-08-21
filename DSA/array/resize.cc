// in a given array , compute such code that stores the length of the array in its 0th index and move elements to its  right position 

#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define logarr(arr, a, b)            \
    for (int i = (a); i <= (b); i++) \
        cout << (arr[i]) << " ";     \
    cout << endl;
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void resize(int *arr, int size) {
    size ++ ;
    arr[0] = size;
    for (int i = 1; i <= size; i++)
    {
        arr[i+1] = arr[i];
        arr[i] = arr[i-1]; /
        
    }
    
} 
int main() {
    int arr[] = {10,20,30,40,60};   
    int size = sizeof(arr)/sizeof(int);
    resize(arr,size );
    logarr(arr,0,size);
    return 0;
}
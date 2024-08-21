#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i < (b); i++)
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
int removeElement(vector<int> &arr, int val)
{
    int k = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++ ) 
    {
        if (arr[i] != val)
        {
            arr[k] = arr[i] ;
            k ++ ; 
        }
    }
    return k ;
}
int main()
{
    vector<int> arr = {10,20,30,40,50} ;
    for(auto i : arr) {
        cout << i << " ";
    }
}
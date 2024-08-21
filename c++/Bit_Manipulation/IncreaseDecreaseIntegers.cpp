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
int main() {
    
    int i = 0 ;
    //bitwis incrementing an integer  
    i = -~i;
    // cout << i  << endl;
    //how to get a binary of a numerb
        int count = __builtin_popcount(3);
        cout << count;
    // find an absolute value of an intger 
    i = -10 ;
int abs = (i ^ (i >> 31)) - (i >> 31);
    cout << abs  ;
 
    return 0;
}
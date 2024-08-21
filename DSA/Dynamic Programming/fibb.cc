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
#define MAX 50
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
int memoTable[MAX +1];
void _initialize() {
    int i = 0 ;
    for(i ; i< MAX ;++ i) {
       memoTable[i] = 0LL;     
    }
}

int fibb (int n) {
    if(memoTable[n] == 0LL) {
        if( n <=1) {
            memoTable[n] =  n;
        }
        else {
            memoTable[n] = fibb(n-1) + fibb(n-2);
        }
    }
    return memoTable[n];
}
int main() {
    _initialize();
    cout << fibb(10);   
    return 0;
}
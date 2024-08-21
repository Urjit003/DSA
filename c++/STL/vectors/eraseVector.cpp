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
    int n , a, b, x;
     cin >> n ;
    vector<int> v ( n); 

    for (int i = 0; i < n; i++)
    {
        int k ;
         cin >>k ;
         v[i] = k ;
    }
    cin >> x >> a >> b; 
    v.erase(v.begin() + x -1 ) ;
    v.erase(v.begin() + a - 1  , v.begin() + b -1);
    cout << v.size() << endl ;
    for(int i : v) {
        cout << i << ' ';
    }
    return 0;
}
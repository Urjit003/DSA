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
bool canBeEqual(vector<int>&target,  vector<int>& arr ) {
    sort(target.begin(),target.end());
    sort(arr.begin(),arr.end());
    return arr == target;
}
int main() {
    vector<int> a = {1,2,3,4,5} ;
    
    vector<int> b = {1,5,4,3,2,90} ;
    
    cout << (canBeEqual(a,b)? " can be equal " : " can not be equal ") << endl;
    return 0;
}
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
ll findSecondLargestInArray(vi arr) {
    sort(arr.begin() , arr.end())  ;
    return arr[arr.size()-2];
}
int main() {
   vi arr = {10,20,30,5,123,2,42,12343}  ;
    cout << findSecondLargestInArray(arr) ;
    return 0;
}
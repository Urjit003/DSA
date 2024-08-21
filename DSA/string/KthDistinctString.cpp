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
string kThDistnict(vector<string>&arr , int k ) {
    int l = 0;
    vector<string> dist ;

    for(int i =0 ; i < arr.size() ; ++i) {
        for(int j = i +1 ; j <arr.size()-1 ;++j) {
            if(arr[i] == arr[j]) {
                l++;
                dist.emplace_back(arr[j]);
            }
        }
    }
    if(l < k)  {
        return  "";
    }
    return dist[arr.size() - l ] ;
} 
int main() {
    
    return 0;
}
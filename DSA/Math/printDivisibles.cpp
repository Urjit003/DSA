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
void printDivisibles(int n) {
    vector<int> divs ;
    int count = 0;
    for (int i = 1;  i*i<= n; i++)
    {
        if(n%i == 0) { 
            divs.push_back(i);
            if((n/i)!= i) {
                divs.push_back(n/i);
            }
        }
    }
    sort(divs.begin(),divs.end());
    // divs.resize(count);
    for(auto i : divs) {
        cout << i << " ";
    }
}
int main() {
   printDivisibles(12) ;
    return 0;
}
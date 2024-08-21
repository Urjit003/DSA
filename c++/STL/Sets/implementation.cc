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
#ifndef ONLINE_JUDGE Test Driven Development 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int main() {
    set<int> s ;
    for(int i = 1 ; i<=10 ; ++i) {
        s.insert(i);
    }
   
    for(auto i : s) {
        cout << i << "\n";
    }
    
    cout << endl;
    set<int>:: iterator itr = s.begin();
    itr++;
    s.erase(itr);

    for(auto i : s) {
        cout << i << "\n";
    }
    
    cout << endl;
}
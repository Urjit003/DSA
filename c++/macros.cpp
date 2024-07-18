#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define logarr(arr,a,b) for(int i = (a); i <= (b); i++) cout << (arr[i]) << ""; cout << endl;
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
vi add(vi x, vi y) {
    reverse (x.begin() , x.end());
}
int main()
{
    file_i_o();
    ll t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        vi s, d;
        loop(i, 0, a.size() - 1)
        {
            s.pb(a[i] - '0');  
        }
        loop(i, 0, b.size() - 1)
        {
            d.pb(b[i] - '0');  
        }
        logarr(s,0,s.size()-1);
        logarr(d,0,d.size()-1);

    }
    return 0;
}
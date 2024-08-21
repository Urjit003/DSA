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
void bin(unsigned n)
{
    if (n > 1)
        bin(n / 2);

    cout << n % 2 ;
}
int main()
{
    auto a = 10, b = 0;
        // cout << (a ^ b ? "True" : "false") << endl; // gives true if both operands are different
        // cout << (a & b ? "True" : "false") << endl; // gives true if both operands are true
    ll c = 5;
    bin(c);
    cout << endl;
    /*
    <<
    (num << shift)
        shift -> will shift the number of bits to left of num .
    */
    c= c << 2;
    bin(c);
    cout << endl;
    cout << c << endl;
    return 0;
}
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
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string prev = countAndSay(n - 1);
    string result = "";
    int count = 1;

    for (int i = 1; i < prev.length(); ++i)
    {
        if (prev[i] == prev[i - 1])
        {
            count++;
        }
        else
        {
            result += to_string(count) + prev[i - 1];
            count = 1;
        }
    }
    result += to_string(count) + prev[prev.length() - 1];

    return result;
}

int main()
{
    cout << "Coutn and say of 4 :" << countAndSay(9) ;
    return 0;
}
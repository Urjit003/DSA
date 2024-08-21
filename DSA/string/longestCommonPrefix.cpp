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


 string longestCommonPrefix( vector< string>& strs) {
    if (strs.empty()) {
        return "";
    }

    string prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && strs[i][j] == prefix[j]) {
            ++j;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) {
            return "";
        }
    }
    return prefix;
}


int main() {
    vector<string> str = {"flower","flow","flight"}    ;
    cout << "hell oworl"<<endl;
    cout << longestCommonPrefix(str) << " ";
    return 0;
}
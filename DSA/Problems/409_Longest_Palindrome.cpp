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
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
// palindrome
//  that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.
map<char,int> table  ;
bool isPalindrome (string s) {
    int l = 0 , r = s.size() - 1 ;
    while (l<r)
    {
        if(!s[l] == s[r]) {
            return false ;
        }
        l++, r--; 
    }
    return true;

}

void longestPalindrome(string s) {
    if(s.size() == 1 ) return    ;
    int l = 0 ,  r =  0 ;
    for(char c  :s )  {
       table[c]++;
    }

}

int main() {
    longestPalindrome("aabbcccccccc") ;
    for(auto c : table) {
        cout << c.first << " " << c.second << endl ;
    }
    return 0;
}
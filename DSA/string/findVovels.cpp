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
int findVowels(string str) {
    int count =0; 
    string vowels = "aeiouAEIOU" ;
    for(char c : str) {
        if(vowels.find(c)!= string::npos) count ++; 
    }
    return count ;

}
int main() {
    int str1 =findVowels("AEiouxyz")  ;
    cout << str1 << endl;
    return 0;
}
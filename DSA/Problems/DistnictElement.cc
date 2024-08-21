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
int DistinctElement(vector<int> &s )
{
    int sum =0 ; 
   if(s.size() <=1 ){
        return s[0];
    }   for(int i : s) {
        sum ^=i;
    }
    return sum ;
}
int main() {
vector<int> ans = {18,49,15,30,56,20,49,67,82,69,84,63,93,87,66,17,38,32,17,32,94,66,67,63,48,64,84,82,87,18,79,64,79,15,71,94,59,5,22,59,4,98,81,4,98,73,69,88,30,81,48,56,71,20,93,22,73,5,88};
    cout << DistinctElement(ans)<< endl;   
    return 0;
}
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

class abc
{
public:
   static vi rotateLeftByD(int d, vi arr)
    {

        int n = arr.size();
        d = d % n;
        vi temp(arr.begin(), arr.begin() + d);
        // logarr(temp,0,temp.size()) ;

        for (int i = d; i < n; i++)
        {
            /* code */
            arr[i - d] = arr[i];
        }

        for (int i = 0; i < d; i++)
        {
            arr[n - d + i] = temp[i];
        }

        return arr;
    }
    static vi rotateLeftByD_REV(int d , vi arr)  {
        d = d % arr.size();

        reverse(arr.begin() , arr.begin() + d) ;
        reverse(arr.begin() + d , arr.end());
        reverse(arr.begin() , arr.end());
        return arr ;
    } 
        
};
int main()
{
    abc a ;
    vi original = {1, 2, 3, 4, 5, 6, 7 , 8};
    vi alterd = a.rotateLeftByD_REV(3, original);

    logarr(alterd, 0, alterd.size() - 1);
    return 0;
}
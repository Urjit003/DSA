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
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        // U
        for (int j = 0; j < 5; j++) {
            if (j == 0 || j == 4 || (i == 4 && j > 0 && j < 4)) 
                cout << "*";
            else 
                cout << " ";
        }
        cout << "  "; // Space between letters
        
        // R
        for (int j = 0; j < 5; j++) {
            if (j == 0 || (i == 0 && j < 4) || (i == 2 && j < 4) || (j == 4 && (i == 1 || i == 3)) || (j == i - 1 && i > 2))
                cout << "*";
            else
                cout << " ";
        }
        cout << "  "; // Space between letters
        
        // J
        for (int j = 0; j < 5; j++) {
            if ((i == 0 && j < 4) || (j == 2 && i < 4) || (i == 4 && j < 3))
                cout << "*";
            else
                cout << " ";
        }
        cout << "  "; // Space between letters
        
        // I
        for (int j = 0; j < 5; j++) {
            if (i == 0 || i == 4 || j == 2)
                cout << "*";
            else
                cout << " ";
        }
        cout << "  "; // Space between letters
        
        // T
        for (int j = 0; j < 5; j++) {
            if (i == 0 || j == 2)
                cout << "*";
            else
                cout << " ";
        }
        
        cout << endl; // Move to the next row for all letters
    }
    
    return 0;
}

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
string xorEncryptDecrypt (string input ,string key)  {
    string output = input ;
    size_t  keyLength = key.size(); 

    for(size_t i = 0 ; i <input.length() ; ++i){
        output[i] = input[i] ^ key[i % keyLength] ;
    }
    return output;
}
int main() {
    
    string plainText = "1123"  , key = "123" ;
    string cipherText = xorEncryptDecrypt(plainText , key) ;


    cout << xorEncryptDecrypt(plainText,key )  ;
    cout << endl ;
    for(unsigned char c : cipherText) {
        cout << hex <<setw(2) << setfill('$') << (int) c << " ";
    }
    cout << endl ;
    cout << "Original text" << endl;
    cout << xorEncryptDecrypt(cipherText,"123");
    return 0;
}

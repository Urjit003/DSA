#include<bits/stdc++.h>
using namespace std;

void staircase(int n) {
    for(int i  = 0 ;i <n ;i++) {
        for(int j =i ; j != n; ++j) {
            cout << "#";
        }
        cout << endl;
    }
}
int main (){
staircase(6);
return 0;
}
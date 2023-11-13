#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 1000
int HashTable[MAX+1][2];
int main (){
    int arr[] = {1,2,4,5,6,123132,2424};

    for(int i: arr) {
        cout << i << " ";
    }
return 0;
}
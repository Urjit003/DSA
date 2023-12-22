#include<iostream>
#include<stdlib.h>
#include "math.h"
#define MAX 1000 
using namespace std;
bool HashTable[MAX+1][2];

bool Search(int x ){
    if (x>0)
    {
        if(HashTable[x][0] == 1) {
            return true;
        }else {
            return false;
        }
    }
    else  {
        x= abs(x);
        if(HashTable[x][1] == 1) 
            return true;
        else 
            return false;
        
    }
}
void print() {
    for (int i = 0; i < MAX+1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << " " << HashTable[i][j];
        }
        cout << "<-- " << i;cout << endl;
    }
    cout << endl;
}
void insert(int arr[],int size) {
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > 0) {
            HashTable[arr[i]][0] = 1 ; // HT[120][0] = true;
        } else {
            HashTable[abs(arr[i])][1] = 1;
        }
    }
}
int main (){
    int *arr;
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < MAX + 1 ; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[j] = j;
        }
        arr[i] = i;
    }
    insert(arr,size);
    int x =-12;
    int Find = Search(x);
    print();
        if(Find) {
            cout << x << " is present";
        }else {
            cout << x << " isn't present";
        }
return 0;
}
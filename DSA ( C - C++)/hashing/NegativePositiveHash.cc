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
void insert(int arr[],int size) {
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > 0) {
            HashTable[arr[i]][0] = 1 ;
        } else {
            HashTable[abs(arr[i])][1] = 1;
        }
    }
}
int main (){
    int arr[] = {120,-120 ,150 , -150};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    insert(arr,size);
    int x = -150 ;
    int Find = Search(x);
        if(Find) {
            cout << x << " is present";
        }else {
            cout << x << " isn't present";
        }
return 0;
}
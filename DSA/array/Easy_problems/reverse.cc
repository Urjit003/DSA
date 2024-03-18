#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
void DisplayVector(vector<int> &arr);
vector<int> MakeVector(int size) {
    vector<int> v ;
    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value for : " << i + 1 << endl;
        int val;
        cin >> val;
        v.push_back(val);
    }
    cout << "Your vector has been made !\n";
    return v;
}
void DisplayVector(vector<int> &arr)
{
    int n = arr.size();
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
}
vector<int> RevArray(vector<int> &arr, int low , int high) {
    cout << "\nYour Reverse array :\n";
    while (high > low)
    {
        int k ;
        k = arr[low];
        arr[low]= arr[high];
        arr[high] = k ;
        low ++ ;
        high -- ;
    }
    return arr;

}
int main()
{
    cout << "Enter the size of your array : ";
    int size;
    cin >> size;
    vector<int> arr = MakeVector(size);
    DisplayVector(arr);
    vector<int> revarr= RevArray(arr,0,arr.size()-1);
    DisplayVector(arr);
    return 0;
}
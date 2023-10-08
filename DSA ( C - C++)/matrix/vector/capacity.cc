#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1;
    v1.reserve(10);
    for (auto i = 1; i <= 1; i++)
    {
        v1.push_back(i);
    }
    cout << "Size : " << v1.size();
    cout << "\nCapacity : " << v1.capacity();
    cout << "\nMax_Size : " << v1.max_size();
    cout << "\nOld Vector elements are\n";
    for (auto i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << " ";
    }

    // resizing it to 4
    v1.resize(4);
    cout << "\nNew Size : " << v1.size();

    if (v1.empty())
    {
        cout << "\nVector is empty";
    }
    else
    {
        cout << "\nVector is not empty";
    }
    v1.shrink_to_fit();
    // cout <<"\nnew size : " << v1.size();
    cout << "\nVector elements are\n";
    for (auto i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}
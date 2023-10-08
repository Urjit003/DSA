#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1;
    for (int i = 1; i <= 5; i++)
    {
        v1.push_back(i);
    }
    cout << "Output from begin to end \n";
    for (auto i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\nOutput from cbegin to cend \n";
    for (auto i = v1.cbegin(); i != v1.cend(); i++)
    {
        cout << *i << " ";
    }
    cout << "\nOutput from rbegin to rend \n";
    for (auto i = v1.rbegin(); i != v1.rend(); i++)
    {
        cout << *i << " ";
    }
      cout << "\nOutput from crbegin to crend \n";
    for (auto i = v1.crbegin(); i != v1.crend(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}
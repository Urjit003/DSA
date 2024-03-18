// reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
// at(g) – Returns a reference to the element at position ‘g’ in the vector
// front() – Returns a reference to the first element in the vector
// back() – Returns a reference to the last element in the vector
// data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1;
    v1.reserve(10);
    // 1 2 3 4 5 6 7 8 9 10
    for (auto i = 1; i <= 10; i++)
    {
        v1.push_back(i);
    }

    cout << "\nReference operator \n[g] : v1[2] = "<< v1[2]; 
    cout << "\nReference to the element at position \n[g] : v1[2] = "<< v1.at(2); 
    cout <<"\nv1.front() \n" << v1.front();
    cout <<"\nv1.back() \n" << v1.back();

    int *pos = v1.data();
    cout <<"\nfirst element in the vector is\n" << *pos;
    return 0;
}
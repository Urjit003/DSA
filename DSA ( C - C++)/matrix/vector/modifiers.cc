// assign() – It assigns new value to the vector elements by replacing old ones
// push_back() – It push the elements into a vector from the back
// pop_back() – It is used to pop or remove elements from a vector from the back.
// insert() – It inserts new elements before the element at the specified position
// erase() – It is used to remove elements from a container from the specified position or range.
// swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
// clear() – It is used to remove all the elements of the vector container
// emplace() – It extends the container by inserting new element at position
// emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
void PrintVector(vector<int> v1)
{
    for (auto i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << " ";
    }
}
int main()
{
    vector<int> v1;
    for (auto i = 1; i <= 10; i++)
    {
        v1.push_back(i);
    }
    // v1.assign(10,10);
    v1.pop_back();
    v1.pop_back();
    v1.insert(v1.end(),9);
    v1.insert(v1.end(),10);
    PrintVector(v1);
    return 0;
}
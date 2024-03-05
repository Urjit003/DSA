#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <iterator>

// argument list for class template "std::iterator" is missingC/C++(441)
using namespace std;
void DisplayVector(std::vector<int>& vector) {
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << " ";
    }
    cout << endl;
    
}
int main()
{
    vector<int> vec1;
    // what does the code above the line mean
    int n ;
    std::cout << "Enter the size of your vector" << std::endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        vec1.push_back(i);
    }
    DisplayVector(vec1);
    vector<int> :: iterator itr = vec1.begin();
    vec1.insert(itr + 1,69);
    DisplayVector(vec1);
    return 0;
}
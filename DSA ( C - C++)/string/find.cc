#include <iostream>
using namespace std;
int main()
{
    string name = "urjit dabhi\n";
    cout << name;
    for (int i = 0; name.length(); i++)
    {
        if (name[i] == ' ')
        {
            cout << "space found at " <<i+1;
            break;
        }
    }
    return 0;
}
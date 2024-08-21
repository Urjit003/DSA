#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


int main()
{
    unordered_map<string , int> countries;
    countries["US"] = 0;
    countries["UK"] = 1;
    countries["CA"] = 2;
    countries["DE"] = 3;
    countries["FR"] = 4;


    for (const auto& country : countries) {
        cout << country.first << " " << country.second << endl;
    }   
     return 0;
}
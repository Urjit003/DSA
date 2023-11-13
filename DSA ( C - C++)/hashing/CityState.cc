// enter capital city where index is the country
// Eg
//     India       -> delhi
//     Switzerland -> Bern
//     USA         -> Washington DC
#include <iostream>
#include <stdlib.h>
#define MAX 1000
using namespace std;
typedef struct
{
    string CountryIndex;
    string CapitalName;
    int counter;
} Node;
Node *HashTable[MAX + 1][2];
void insert(string CountryName, string CapitalName)
{
    Node *newNode = new Node;
    int LengthOfCountryName = CountryName.length();
    newNode->CountryIndex = CountryName;
    newNode->CapitalName = CapitalName;
    newNode->counter = 0;

    // Store the new Node in the hash table
    HashTable[LengthOfCountryName][1] = newNode;
    // n->CountryIndex = LengthOfCountryName;
    // n->CapitalName = CapitalName;
}
string find(string CountryName)
{
    int i = 0;
    int LengthOfCountryName = CountryName.length();
    if ( HashTable[LengthOfCountryName] == nullptr || HashTable[LengthOfCountryName][1] == nullptr) 
        return "Not found";
    else
        return HashTable[LengthOfCountryName][1]->CapitalName;
}
int main()
{
    // insert(arr,"India", "delhi")
    // find("delhi")
    // find == 1 , true -> it is present
    insert("India", "delhi");
    insert("Switzerland", "Bern");
    insert("Pakistan", "Islamabad");

    string res = find("Angola");

    cout << res;
    return 0;
}
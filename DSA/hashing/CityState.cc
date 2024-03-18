// enter capital city where index is the country
// Eg
//     India       -> delhi
//     Switzerland -> Bern
//     USA         -> Washington DC
//      ASCII 
#include <iostream>
#include <stdlib.h>
#define MAX 50
using namespace std;
typedef struct Node
{
    string CountryIndex;
    string CapitalName;
    int counter;
} Node;
Node *HashTable[MAX + 1][2];
void print() {
    for (int i = 0; i < MAX + 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << HashTable[i][j]<< endl;
        }
        cout << endl;
    }
    
}
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
    int arr[10] ;
    arr[0] = 10;
    // insert(arr,"India", "delhi")
    // find("delhi")
    // find == 1 , true -> it is present
    insert("India","delhi");
    insert("Pakistan","Islamabad");

    string res = find("Pakistan");
    print();
    cout << res;
    return 0;
}
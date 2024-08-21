#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void print(int n)
{
    cout << n << endl;
    if (n == 0)
        return;

    print(--n);
}
void oneToN(int n)
{
    if (n > 0) {
        oneToN(--n) ;
        cout << n << endl;
    }
 }
int main()
{
    print(5);
    return 0;
}

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
        oneToN(n-1) ;
        cout << n << endl;
    }
 }
int main()
{
    oneToN(5);
    return 0;
}

#include <iostream> 
#include <stdlib.h>

using namespace std;
int main () {
    for(int i=1 ; i<=100 ;i++) {
        if (i%3==0 && i%5==0) {
            cout << "buzzfizz " << endl;
        }
        if (i%3==0 ) {
            cout << "buzz " << endl;
        }
        else if ( i%5==0)
        {
            cout << "fizz " << endl;

        }
        else {
            cout << i << " ";
        }
    }

    return 0;
}
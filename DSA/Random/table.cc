#include <iostream> 
using namespace std;

int main() {
    for (int i=1;i<=50;i++) {
        for (int j=1;j<=10;j++) {
            cout << i << "x" << j << " = " << i*j << "\n";
            // cout << "" << i <<""<<j << "" << i*j;
        }
        cout << endl;
    }

    return 0;
}

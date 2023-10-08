#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    char names[] = {'1', '2', '3'};
    int namesize = sizeof(names) / sizeof(char);
    long long int arr[] = {6935622003, 6935622003, 6935622003};

    int target = 0;
    for (int i = 0; i < namesize; i++)
    {
        cout << names[i] << ":" << arr[i] << endl;
        ;
    }
    cout << "Enter your choice 0 to enter name and its number or 1 to not add\n";
    bool choice;
    cin >> choice;
    while (!choice)
    {
        cout << "Hello";
        cout << "\nEnter your character : ";
        char inputchar;
        cin >> inputchar;
        names[namesize] = inputchar;
        names[namesize+1]= '\0';

        for (int i = 0; i < namesize; i++)
        {
            cout << names[i];
        }
        
        choice = true;
    }

    return 0;
}
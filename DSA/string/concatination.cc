#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
    //    { using '+' operator :
    //    string st1 = "hello",st2 = "world";
    //     cout << st1 + st2 ;
    // }

    /* using append function*/
    // string s1 = "hello",s2="World";
    // s1.append(s2);
    // cout << s1;

    /*using strcat() method*/
    // char s1[] = "hello",s2[]="World";
    // strcat(s1,s2);
    // cout << s1;

    /*using for loop*/
    string s1 = "hello",s2="World";
    string output ;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        output += s1[i];
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        output += s2[i];
    }
    cout << output;
    return 0;
}
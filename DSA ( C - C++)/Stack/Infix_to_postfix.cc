#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '(') 
        return 0;
    else
        return -1;
}
string InfixToPostfix(string exp)
{
    string postfix;
    stack<char> st;
    char c;
    for (int i = 0; i < exp.length(); i++)
    {
        c = exp[i];
        // if the scanned char is operand
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix += c;
        }
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            // if the scanned char is operator
            while (!st.empty() && precedence(exp[i]) <= precedence(st.top()))
            {
                postfix += c;
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
         postfix += st.top();
         st.pop();
    }
    return postfix;
}
int main()
{
    string str = "(a+b)*(c/d)";
    string newstr = InfixToPostfix(str);
    cout << newstr ;
    return 0;
}
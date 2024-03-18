#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int EvaluatePost(string exp);
int EvaluatePostOPT(string exp);
int EvaluatePost(string exp)
{
    stack<int> st;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        // the i is an operand
        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        // if i is an operator
        else
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();

            switch (ch)
            {
            case '+':
                st.push(B + A);
                break;
            case '-':
                st.push(B - A);
                break;
            case '*':
                st.push(B * A);
                break;
            case '/':
                st.push(B / A);
                break;
            default:
                break;
            }
        }
    }

    return st.top();
}
int EvaluatePostOPT(string exp)
{
    string postfix;
    stack<int> st;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ')
            continue;

        // scanned char is an operand
        else if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
        // scanned char is an operator
        else
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();

            switch (exp[i])
            {
            case '+':
                st.push(B + A);
                break;
            case '-':
                st.push(B - A);
                break;
            case '*':
                st.push(B * A);
                break;
            case '/':
                if (A == 0)
                {
                    cerr << "DIVIOSN BY ZERO" << endl;
                    return INT_MIN;
                }
                st.push(B / A);
                break;
            default:
                break;
            }
        }
    }
    if (st.size() != 1)
    {
        cerr << "Error: Malformed expression" << endl;
        return INT_MIN;
    }
    return st.top();
}
int main()
{
    string str = "200 100 +";
    int res = EvaluatePostOPT(str);
    cout << res;
    return 0;
}

// 2 3 1 * + 9 -
// 2 push
// 3 push
// 1  push
//  * , pop A , B respectively , A = stack top , B = stack top -1
//  store (RESULT = A OPERATOR B )into top stack , push RESULT

//  + , pop
//
// 3
// 2
#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define logarr(arr, a, b)            \
    for (int i = (a); i <= (b); i++) \
        cout << (arr[i]) << " ";     \
    cout << endl;
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vector<int> splitAndConvert(const string &str)
{
    vector<int> numbers;
    stringstream ss(str);
    string token;

    while (getline(ss, token, ':'))
    {
        if (!token.empty())
        {
            numbers.push_back(stoi(token));
        }
    }
    return numbers;
}

string timeConversion(string s)
{
    vector<int> res = splitAndConvert(s);

    if (s.find("AM") != string ::npos || s.find("am") != string ::npos)
    {
        if (res[0] == 12)
            res[0] = 00;
        // res[0] += 0;
    }
    else if (s.find("PM") != string ::npos || s.find("pm") != string ::npos)
    {
        if (res[0] != 12)
        {
            res[0] += 12;
        }
    }
    else
    {
        return "INVALID";
    }
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << res[0] << ":"
       << std::setfill('0') << std::setw(2) << res[1] << ":"
       << std::setfill('0') << std::setw(2) << res[2];

    return ss.str();
}
int main()
{
    int x = 10;
    cout << "before setting 10 width " << endl
         << x << endl;
    cout << setfill('-');
    cout << "AFter setting 10 width" << endl
         << setw(2);
    cout << x;
    return 0;
}
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
        res[0] += 12;
    }
    else
    {
        return "INVALID";
    }
    string ans;

    for (auto n : res)
    {
        if(n == res.at(1) || n == res.at(3)) {
            ans += "0";
        }
        ans += to_string(n) + ":";
    }
    return ans.substr(0,ans.size()-1);
}
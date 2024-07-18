#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define logarr(arr,a,b) for(int i = (a); i <= (b); i++) cout << (arr[i]) << ""; cout << endl;
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
string day_of_programmer(int year) {
	int remaining_days = 0;
	if(year <= 1700 || year >= 2700)
		exit(1);
	bool LeapYear = false;
	if(year < 1919) {
		LeapYear = (year % 4 == 0);
	}else {
		LeapYear = (year % 400 == 0) || (year % 4 == 0 && !(year % 100 == 0));

	}
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
		if (LeapYear)
	    {
	        months[1] = 29;
	    }
	    for (int i = 0; i < 12; i++)
	    {
	        days += months[i];
	        if(i ==7)
	            break;
	       
	    }
	    if(year == 1918) { LeapYear ? days-=14 : days-=13;}
 		remaining_days = 256 - days;
   		 string formated_year = to_string(remaining_days) + "." + "09"+ "." + to_string(year);
    return formated_year;
}
int main()
{
    file_i_o();
    int t;
    cin >> t; 
    while(t--) {
    	int year;
    	cin >> year ;
    	cout << day_of_programmer(year) << endl;
    }
    return 0;
}
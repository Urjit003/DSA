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
void multiply (vi& ans, int num) {
	int carry = 0 ;
	loop(i  ,0 , ans.size() -1 ) {
		ll prod = ans[i]*num + carry;
		carry = prod / 10 ;
		ans[i] = prod % 10;
	}
	while(carry) {
		ans.pb(carry%10) ;
		carry /= 10;
	}
}
void factorial(int n) {
	vi ans ;
	ans.pb(1);
	loop(i , 2, n) {
		multiply(ans , i );
	}
	reverse(ans.begin(),ans.end());
	logarr(ans, 0 , ans.size()-1) ;
}
vi add (vi x , vi y) {
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	ll len= min(x.size(),y.size());
	ll carry = 0;
	vi ans;
	loop(i , 0 , len - 1)  {	
		ll val = x[i] + y[i] + carry;
		carry = val/10;
		ans.pb(val%10);
	}	
		if(x.size() > len) {
			loop(i , len , x.size() - 1) {
				ll val = x[i] + carry ;
				carry = val/10;
				ans.pb(val%10);
			}
		}
		loop(i,len ,y.size()-1) {
		if(y.size() > len) {
				ll val = y[i] + carry;
				carry = val/10;
				ans.pb(val%10);
			}
		}
		while(carry) {
			ans.pb(carry%10);
			carry /= 10;
		}
		reverse(ans.begin(),ans.end());
		return ans;
}
int main()	
{
    file_i_o();
    ll t;
    cin >> t ;
    while(t--) {
    	ll n ;
    	cin >> n ;
    	// factorial(n);
    	
    	// logarr(sum,0,sum.size()-1 );
    	// logarr(d,0,d.size()-1);

    }
    return 0;
}
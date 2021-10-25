#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) { return y ? gcd(y,x%y) : x; } 

inline ll phi(ll x){
	ll ans=x;
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0)x/=i;
		}
	}
	if(x>1)ans=ans/x*(x-1);
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t --)
	{
		ll m,a;
		cin >> a >> m;
		cout << phi(m / gcd(a,m )) << endl;
	}
	return 0;
}

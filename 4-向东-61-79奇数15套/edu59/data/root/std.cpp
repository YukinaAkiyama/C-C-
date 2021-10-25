#include <bits/stdc++.h>
#define rep(i,x,y) for(register int i = x; i <= y; ++ i)
#define repd(i,x,y) for(register int i = x; i >= y ; -- i) 
using namespace std;
typedef long long ll;

template<typename T>inline void read(T&x)
{
	int sign = 1; x = 0; char c;
	do { c = getchar (); if(c == '-') sign = -1; }while(!isdigit(c));
	do { x = x * 10 + c - '0'; c = getchar(); }while(isdigit(c));
	x *= sign;
}

const int mod = 998244353,N = 2e5 + 50;
int n,m;

int quick_pow(int x,int y)
{
	int ans = 1;
	while(y)
	{
		if(y&1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return ans;
}

int f[N];

int main()
{
	read(n); read(m);
	f[1] = 1;
	rep(i,2,m) f[i] = 1ll * f[i-1] * i % mod;
	if(n == 2) cout << 0 ;
	else cout << 1ll * f[m] *quick_pow(f[n-1],mod-2)%mod * quick_pow(f[m-n+1],mod - 2)%mod * (n-2) %mod *quick_pow(2,n - 3) % mod;
	return 0;
}

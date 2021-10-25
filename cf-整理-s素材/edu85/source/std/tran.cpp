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

const int N = 1e5+ 50;
int t,n,m,ans,a[N];ll cnt; 

int main()
{
	read(t);
	while(t--)
	{
		ans = 0; cnt = 0;
		read(n); read(m);
		rep(i,1,n) read(a[i]);
		sort(a + 1,a + 1 + n);
		repd(i,n,1) 
		{
			if(a[i] + cnt < m) break;
			if(a[i] > m) cnt += a[i] - m;
			if(a[i] < m) cnt -= m - a[i];
			ans ++;
		}
		cout << ans << endl;
	}
	return 0;
}

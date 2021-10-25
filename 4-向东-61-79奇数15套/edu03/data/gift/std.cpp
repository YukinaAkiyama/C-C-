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

int n,a[101];

int main()
{
	int t;
	cin >> t;
	while(t --)
	{
		read(n);
		rep(i,1,n) read(a[i]);
		sort(a + 1,a + 1 + n);
		repd(i,n,1) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}

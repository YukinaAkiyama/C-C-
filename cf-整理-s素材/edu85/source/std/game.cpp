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

const int N = 1e2+ 50;
int t,n,p[N],c[N]; 

int main()
{
	read(t);
	while(t--)
	{
		read(n);bool k = 1;
		p[n] = 0;c[n] = 0;
		while(n--)
		{
			read(p[n]); read(c[n]);
			if(p[n] - p[n + 1] < c[n] - c[n + 1] || p[n] < p[n+1] || c[n] < c[n + 1] || p[n] < c[n])
				k = 0;
		}
		puts(k ? "YES" : "NO");
	}
	return 0;
}

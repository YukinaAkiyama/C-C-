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

int n,k;
bool vis[31];
priority_queue<ll> q;
int main()
{
	int t;
	cin >> t;
	while(t --)
	{
		read(n); read(k); 
		ll x,MAX = 1; 
		rep(i,1,n) 
		{
			read(x);
			if(x) q.push(x);
			MAX = max(MAX,x);
		}
		x = 1;
		while(x * k <= MAX) x *= k;
		while(x && !q.empty())
		{
			if(q.top() >= x)
			{
				ll z = q.top(); 
				q.pop(); z-= x; 
				if(z) q.push(z);
			}
			 
			x /= k;
		}
		puts(q.empty() ? "YES" : "NO");
		while(!q.empty()) q.pop();
	}
	return 0;
}

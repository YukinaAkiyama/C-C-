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
 
const int N = 5e2 + 50;
int n;
int a[N],m[N][N],f[N][N];
 
int main()
{
	read(n);
	
	rep(i,1,n) read(a[i]);
	
	memset(f,0x3f,sizeof f);
	rep(i,1,n) f[i][i] = 1,m[i][i] = a[i];
	
	repd(i,n,1) rep(j,i + 1,n) rep(k,i + 1,j)
	{
		f[i][j] = min(f[i][j],f[i][k-1] + f[k][j]);
		if(f[i][k - 1] == 1 && f[k][j] == 1 && m[i][k - 1] == m[k][j])
			f[i][j] = 1,
			m[i][j] = m[k][j] + 1;
	}
	
	cout << f[1][n] << endl;
	
	return 0;
}

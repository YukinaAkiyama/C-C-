#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
#define rep(i,x,y) for(register int i = x; i <= y; ++ i)
#define random(l,r) (((1ll*rand()* 998244353) %((r) - (l) + 1)) + (l))
using namespace std;

int quick_pow(int x,int y)
{
	int ans = 1;
	while(y)
	{
		if(y&1) ans = ans * x;
		x = x * x; y >>= 1;
	}
	return ans;
}

int a[502];
void dfs(int l,int r,int w)
{
	if(l == r) return void(a[l] = w);
	int mid = random(l,r-1);
	w = (w - 1);
	dfs(l,mid,w); dfs(mid + 1,r,w);
}

int main()
{
	srand((unsigned long long)new char);
	int n = 500;
	cout << n << endl;
	dfs(1,n,random(500,1000));
	int t = random(1,n);
	while(t -- )
	{
		int x = random(1,n);
		a[x] += 1;
	}
	rep(i,1,n) printf("%d ",a[i]);
	return 0;
}

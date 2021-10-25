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

int p[1001],c[1001];
int main()
{
	srand((unsigned long long)new char);
	int t = 10,n,m = 900;
	
	cout << t << endl;
	while(t --)
	{
		int n = random(1,10); m = m - n + 1;
		int l = random(1,n*(n-1) + 1),r = random(1,n*(n-1) + 1);
		if(l > r) swap(l,r);
		if(r - l + 1> 1e5) r = l + 1e5 - 1;
		printf("%d %d %d\n",n,l,r);
	}

	return 0;
}

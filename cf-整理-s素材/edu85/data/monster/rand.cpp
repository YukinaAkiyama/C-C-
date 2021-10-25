#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
#define rep(i,x,y) for(register int i = x; i <= y; ++ i)
#define random(l,r) (((1ll*rand()* 998244353) %((r) - (l) + 1)) + (l))
using namespace std;
typedef long long ll;

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

const ll MAX = 1e12;
int p[1001],c[1001];
int main()
{
	srand((unsigned long long)new char);
	int t = random(100000,150000),n,m = 150000;
	
	cout << t << endl;
	while(t --)
	{
		int n = random(1,m); m = m - n + 1;
		printf("%d\n",n);
		rep(i,1,n) printf("%lld %lld\n",random(1,MAX),random(1,MAX));
	}

	return 0;
}

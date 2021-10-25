#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
#define rep(i,x,y) for(register int i = x; i <= y; ++ i)
#define random(l,r) (((1ll*rand()* 998244353) %((r) - (l) + 1)) + (l))
using namespace std;
typedef long long ll;
const ll MAX = 1e16;

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

ll a[101]; 

int main()
{
	srand((unsigned long long)new char);
	int t = 1000,n,k;
	cout << t << endl;
	rep(i,1,t) 
	{
		memset(a,0,sizeof a);
		n = random(10,30),k = random(2,100);
		printf("%d %d\n",n,k);
		ll x = 1;
		rep(i,1,1000)
		{
			int z = random(1,n);
			if(a[z] + x <= MAX) a[z] += x;
			x *= k;
			if(x >= MAX) break;
		}
		
		if(rand() & 1)
		{
			int z = rand();
			while(z--)
			{
				int pos = random(1,n),w = rand();
				if(a[pos] + w <= MAX) a[pos] += w;
			}
		}
		
		rep(i,1,n) printf("%lld ",a[i]);
		puts("");
	}
	return 0;
}

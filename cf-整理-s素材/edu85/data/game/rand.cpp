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
	int t = 10,n,m;
	
	cout << t << endl;
	while(t --)
	{
		n = 10;
		cout << n << endl;
		rep(i,1,n) p[i] = random(1,10000),c[i] = random(1,10000);
		sort(p + 1,p + 1 + n);
		sort(c + 1,c + 1 + n);
		int k = rand() % 2;
		if(k)
		{
			rep(i,1,n) if(p[i] < c[i]) swap(p[i],c[i]);
			sort(p + 1,p + 1 + n);
			sort(c + 1,c + 1 + n);
			rep(i,1,n) if(p[i] - p[i-1] < c[i] - c[i - 1])
			{
				p[i] += c[i] - c[i - 1] + p[i-1];
			}
			rep(i,1,n) printf("%d %d\n",p[i],c[i]);
		}
		else 
		{
			k = rand() % 2;
			if(k)
			{
				int z = rand();
				while(z--)
				{
					int a = random(1,n),b = random(1,n);
					swap(p[a],p[b]); swap(c[a],c[b]);
				}
				rep(i,1,n) printf("%d %d\n",p[i],c[i]);
			}
			else
			{
				
				rep(i,1,n) printf("%d %d\n",max(p[i],c[i]),min(p[i],c[i]));
			}
		}
	}

	return 0;
}

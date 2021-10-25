#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
#define rep(i,x,y) for(register int i = x; i <= y; ++ i)
#define random(l,r) (((1ll*rand()* 998244353) %(1ll * (r) - (l) + 1)) + (l))
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

const int N = 1e5 + 50,MAX = 1e9;
int a[N];
int main()
{
	srand((unsigned long long)new char);
	int t = 1000,n,m = 90000;
	
	cout << t << endl;
	while(t --)
	{
		n = random(1,m); m = m - n + 10;
		rep(i,1,n) a[i] = random(1,MAX);
		int x = a[random(1,n)];
		printf("%d %d\n",n,x);
		rep(i,1,n) printf("%d ",a[i]);
		puts("");
	}

	return 0;
}

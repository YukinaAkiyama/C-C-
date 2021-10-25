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

int main()
{
	srand((unsigned long long)new char);
	int t = 10000,n,m;
//	cout << t << endl;
//	rep(i,1,t) 
//	{
//		n = random(2,100);
//		m = random(2,n);
//		printf("%d %d\n",n,m);
//	}

	n = random(2,200000);
	m = random(2,200000);
	printf("%d %d\n",min(n,m),max(n,m));
	return 0;
}

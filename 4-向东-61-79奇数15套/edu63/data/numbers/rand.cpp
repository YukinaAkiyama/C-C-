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
	int t = 100,n = 100,k;
	cout << t << endl;
	rep(i,1,t) 
	{
		printf("%d\n",n);
		rep(i,1,n) printf("%d ",random(1,100));
		puts("");
	}
	return 0;
}

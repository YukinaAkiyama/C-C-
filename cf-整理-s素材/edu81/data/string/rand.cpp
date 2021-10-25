#include <bits/stdc++.h>
#include <sys/time.h>
#include <unistd.h>
#define rep(i,x,y) for(register int i = x; i <= y; ++ i)
#define random(l,r) (((1ll*rand()* 998244353) %((r) - (l) + 1)) + (l))
using namespace std;

const int MX = 1e9;
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
//	int t = random(5,10);
	int t = 10;
	cout << t << endl;

	rep(i,1,t) 
	{
		int k = random(10,25);
		int n = random(1000,10000);
		int m = random(5000,10000);
		rep(i,1,n) printf("%c",random(0,k) + 'a'); puts("");
		rep(i,1,m) printf("%c",random(0,k) + 'a'); puts("");
	}
	return 0;
}

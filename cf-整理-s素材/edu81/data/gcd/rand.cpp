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
//	int t = random(50,100);
	int t = 50;
	cout << t << endl;
	int x = random(3,4);
	rep(i,1,t) 
	{
		cout << random(1000000,10000000000) << ' ' << random(1000000,10000000000)  << endl;
	}
	return 0;
}

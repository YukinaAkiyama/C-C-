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
	int t = 100;
	cout << t << endl;
	int x = random(3,4);
	rep(i,1,t) 
	{
		int out = random(quick_pow(10,x),quick_pow(10,x + 1)); 
		if(out == 1) { --i ; continue; }
		cout << out << endl;
	}
	return 0;
}

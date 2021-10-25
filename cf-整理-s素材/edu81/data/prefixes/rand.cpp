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
	int t = 100;
	cout << t << endl;
	int n = 100000;
	rep(i,1,t) 
	{
		int x = random(-MX,MX),y = random(1,n - 1);
		n -= y;
		if(i % 3 == 0 ) x = 0 ;
		cout <<y << ' ' << x << endl; 
		rep(i,1,n) cout << random(0,1); cout<<endl;
	}
	return 0;
}

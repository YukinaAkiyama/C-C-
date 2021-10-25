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

const int N = 2e5 + 50,MX=1e9;
int a[N];

int main()
{
	srand((unsigned long long)new char);
//	int t = random(50,100);
	int n = 200000;
	cout << n << endl;
	rep(i,1,n) a[i] = i;
	random_shuffle(a + 1,a + 1 + n);
	rep(i,1,n) printf("%d ",a[i]); puts("");
	rep(i,1,n) printf("%d ",random(1,MX));
	return 0;
}

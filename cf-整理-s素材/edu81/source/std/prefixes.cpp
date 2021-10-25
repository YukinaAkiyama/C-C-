#include <bits/stdc++.h>
using namespace std;
string s; 
int n ,t ,x ,mi ,mx ,cnt ,ans;
const int N = 1e5 + 50;
int vis[2*N],num[2*N];
int main()
{

	cin >> t;
	for(int i = 1;i <= t; ++ i)
	{
		cin >> n >> x;
		cin >> s; x += N;
		ans = 0; cnt = N ;
		mi = N + 1,mx = N - 1;
		for(auto j : s)
		{
			cnt += j =='0' ? 1 : -1;
			if(vis[cnt] == i) ++ num[cnt] ;
			else vis[cnt] = i,num[cnt] = 1;
			mi = min(mi,cnt); mx = max(mx,cnt);
		}
		if(x == N) ans = 1;
		if(cnt == N) puts(mx >= x && mi <= x ? "-1" : "0");
		else 
		{
			for(int j = mi;j <= mx; ++ j)
				if((x - j) % (cnt - N) == 0 && (x-j)/ (cnt-N) >= 0)
					ans += num[j];
			cout << ans << endl;
		}
	}
	return 0;
}

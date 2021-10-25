#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4; 
string s,t;
int T,nxt[N][26];
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> s;
		cin >> t;
		int l1 = s.length();
		for(int i = 0;i <= 25;++ i) nxt[l1-1][i] = -1;
		for(int i = l1 - 1;i;--i)
		{
			for(int j = 0; j <= 25; ++ j)
				nxt[i-1][j] = nxt[i][j];
			nxt[i-1][s[i] - 'a'] = i;
		}
		int l2 = t.length(); int ans = 1,now = l1;
		for(int i = 0;i <= 25;++ i) nxt[now][i] = nxt[0][i]; nxt[now][s[0] - 'a'] = 0;
		for(int i = 0;i < l2; ++ i)
		{
			int x = t[i] - 'a';
			if(nxt[l1][x] == -1) { ans = -1; break; }
			if(nxt[now][x] == -1) ++ ans, now = nxt[l1][x];
			else now = nxt[now][x];
		}
		cout << ans << endl;
		
		for(int i = l1 - 1;i >= 0;--i)
			for(int j = 0; j <= 25; ++ j)
				nxt[i][j] = 0;
	}
	return 0;
}

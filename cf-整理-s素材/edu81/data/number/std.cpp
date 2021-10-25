#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , t , x;
	cin >> t;
	while(t --)
	{
		cin >> n; x = n / 2;
		if(n&1) cout << 7 , -- x;
		while( x --) cout << 1;
		cout << endl;
	}
	return 0;
}

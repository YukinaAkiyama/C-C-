#include <bits/stdc++.h>
#define rep(i,x,y) for(register int i = x ;i <= y; ++ i)
using namespace std;
typedef long long ll;
const int N = 4e5+5;
struct segment_tree
{
	ll mi[N << 2],lzy[N << 2];
	
	inline void put_down(int id)
	{
		mi[id] += lzy[id];
		lzy[id << 1] += lzy[id];
		lzy[id << 1|1] += lzy[id];
		lzy[id] = 0;
	}
	
	void add(int id,int l,int r,int L,int R,ll w)
	{
		put_down(id);
		if(l == L&& R == r)
		{
			lzy[id] = w;
			put_down(id);
			return ;
		}
		int mid = l +  r>> 1;
		if(R <= mid) add(id<<1,l,mid,L,R,w);
		else if(L > mid) add(id<<1|1,mid+1,r,L,R,w);
		else add(id<<1,l,mid,L,mid,w),add(id<<1|1,mid+1,r,mid+1,R,w);
		mi[id] = min(mi[id<<1],mi[id<<1|1]);
	}
}t;
int p[N],a[N],id[N];
const bool cmp(int x,int y) { return p[x] < p[y]; }
int main()
{
	int n;
	cin >> n;
	rep(i,1,n) cin >> p[i];
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) id[i] = i;
	
	ll res = 0;
	rep(i,1,n)
	{
		res += a[i];
		t.add(1,1,n,i,i,res);
	}
	sort(id + 1,id + 1 + n,cmp);
	
	ll ans = t.mi[1];
	rep(i,1,n)
	{
		int x = id[i]; 
		if(x != n) t.add(1,1,n,x,n,-a[x]);
		if(x != 1) t.add(1,1,n,1,x-1,a[x]);
		ans = min(ans,t.mi[1]);
	}
	
	cout << ans << endl;
	return 0;
}

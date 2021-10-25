#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll n,l,r;
		scanf("%lld%lld%lld",&n,&l,&r);
		ll a=1,b=1;
		while(((n-a)+(n-1))*a<l&&a<n) a++;
		while(((n-b)+(n-1))*b<r&&b<n) b++;
		if(a==n){
			printf("1\n");
			continue;
		}
		l-=(n*2-a)*(a-1);
		r-=(n*2-b)*(b-1);
		if(a==b){
			for(ll i=l;i<=r;i++){
				if(i&1) printf("%lld ",a);
				else{printf("%lld ",(i/2+a));}
			}
			printf("\n");
			continue;
		}
		for(ll i=l;i<=(n-a)*2;i++){
			if(i&1) printf("%lld ",a);
			else{printf("%lld ",(i/2+a));}
		}
		ll t=a+1;
		while(t<=b-1){
			for(ll i=t+1;i<=n;i++){
				printf("%lld %lld ",t,i);
			}
			t++;
		}
		if(b==n){
			printf("1\n");
			continue;
		}
		for(ll i=1;i<=r;i++){
			if(i&1) printf("%lld ",b);
			else{printf("%lld ",(i/2+b));}
		}
		printf("\n");
		
	}
	
}

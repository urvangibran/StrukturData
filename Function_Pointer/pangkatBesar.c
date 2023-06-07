#include <stdio.h>
typedef long long ll;

ll pangkatBesar(ll a, ll b){
	ll res = 1;
	while(b>0){
		if(b&1) res = (res * (a));
		
		b = b >> 1;
		a = (a*a) ;
	}
	return res;
}

int main(){
	ll a,b;
    scanf("%lld %lld", &a, &b);
	printf("%lld", pangkatBesar(a,b));
	return 0;
}
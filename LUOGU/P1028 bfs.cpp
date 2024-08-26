#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
typedef long long ll;
using namespace std;
struct NUM{ll now,last;}h;
queue<NUM>q;
ll n,ans,t,k;

int main(){
	scanf("%lld",&n);
	q.push((NUM){n,n});
	while(!q.empty()){
		h=q.front();
		q.pop();
		ans++;
		for(ll i=1;i<=n&&i<=h.last/2;i++){
			t=0,k=h.now;
			while(k){
				k/=10;
				t++;
			}
			int ow=i*pow(10,t*1.0)+h.now;
			q.push((NUM){ow,i});
		}
	}
	printf("%lld",ans);
	return 0;
}

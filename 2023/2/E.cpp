#include <iostream>
#include <cstdio> 
#include <cmath>
#include <deque>
#include <cstring>
using namespace std;

const int N=5e5+10;
long long n,L,R,s[N],b[N],dis[N],ans;
deque<int>q;

int main(){
	scanf("%lld%lld%lld",&n,&L,&R);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&dis[i],&s[i]);
	
	memset(b,128,sizeof(b));
	b[0]=0;
	int now=0;
	for(int i=1;i<=n;i++){
		while(dis[now]+L<=dis[i]){
			while(!q.empty()&&b[q.back()]<=b[now])
				q.pop_back();
			q.push_back(now);
			now++;
		}
		while(!q.empty()&&dis[q.front()]+R<dis[i])
			q.pop_front();
		if(!q.empty())b[i]=b[q.front()]+s[i];
//		for(int i=1;i<=n;i++)cout<<b[i]<<endl;
		ans=max(ans,b[i]);
	}
	printf("%lld",ans);
	return 0;
}

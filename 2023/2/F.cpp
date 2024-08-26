#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
using namespace std;

const int N=500010;
int n,d,k,dis[N],s[N],b[N];
deque<int>q;

bool check(int h){
	int ll=max(1,d-h),rr=d+h;
	memset(b,128,sizeof(b));
	b[0]=0;
	int now=0,ans=0;
	for(int i=1;i<=n;i++){
		while(dis[now]+ll<=dis[i]){
			while(!q.empty()&&b[q.back()]<=b[now])
				q.pop_back();
			q.push_back(now);
			now++;
		}
		while(!q.empty()&&dis[q.front()]+rr<dis[i])
			q.pop_front();
		if(!q.empty())b[i]=b[q.front()]+s[i];
		ans=max(ans,b[i]);
	}
	return ans>=k;
}

int main(){
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&dis[i],&s[i]);

	int l=0,r=2001;
	while(l<r){
		int mid=l+(r-l)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l==2001)printf("-1\n");
	else printf("%d\n",l);
	return 0;
}

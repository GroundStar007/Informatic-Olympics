#include <iostream>
#include <cstdio>
#include <deque>
#include <cmath>
using namespace std;

const int N=100009;
int n,S,T,val[N];
double l,r,ans=-10000,s[N];
deque<int>q;

bool check(double k){
	int now=0;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+val[i]-k;
	for(int i=1;i<=n;i++){
		if(i>=S){
			while(!q.empty()&&s[q.back()]>=s[now])
				q.pop_back();
			q.push_back(now);
			now++;
		}
		while(!q.empty()&&i-q.front()>T)
			q.pop_front();
		if(!q.empty()){
			ans=max(ans,s[i]-s[q.front()]);
			if(ans>=0)return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d%d",&n,&S,&T);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	
	l=-10000,r=10000;
	while(r-l>1e-5){
		double mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%.3lf",l);
	return 0;
}

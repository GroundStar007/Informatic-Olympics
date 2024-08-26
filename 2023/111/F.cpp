#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N,Tmax,d[10009],t;

bool check(int x){
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=N;i++){
		if(i<=x){
			q.push(d[i]);
			if(d[i]>Tmax)return false;
		}
		else{
			t=q.top();
			q.push(t+d[i]);
			q.pop();
			if(t+d[i]>Tmax)return false;
		}
	}	
	return true;
}

int main(){
//	freopen("1.txt","r",stdin);
	scanf("%d %d",&N,&Tmax);
	for(int i=1;i<=N;i++)
		scanf("%d",&d[i]);
	int l=1,r=N+1,mid;
	while(l<r){
		mid=l+(r-l)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l==N+1)printf("-1");
	else printf("%d",l);
	return 0;
}

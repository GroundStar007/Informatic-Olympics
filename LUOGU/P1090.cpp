#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> >q;
int n,a,m,k;
long long ans;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		q.push(a);
	}
	while(1){
		if(q.size()==1)break;
		m=q.top(),q.pop();
		k=q.top(),q.pop();
		ans+=m+k;
		q.push(m+k);
	}
	printf("%lld",ans);
	return 0;
}

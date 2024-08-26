#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>
using namespace std;

deque<int>q;
int n,m,num,s[300009],ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		s[i]=num+s[i-1];
	}	

	q.push_back(0);
	ans=s[1];
	for(int i=1;i<=n;i++){
		while(i-q.front()>m) q.pop_front();
		ans=max(ans,s[i]-s[q.front()]);
		while(!q.empty()&&s[q.back()]>=s[i])
			q.pop_back();
		q.push_back(i);
	}
	printf("%d",ans);
	return 0;
}

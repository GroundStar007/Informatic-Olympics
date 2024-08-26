#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

deque<int>q;
int n,k,num[100009];

int main(){
//	freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);

	for(int i=1;i<=n;i++){
		while(!q.empty()&&num[q.back()]>num[i])
			q.pop_back();
		q.push_back(i);
		while(i-q.front()>k)q.pop_front();
		if(i>=k){
			printf("%d ",num[q.front()]);
			q.pop_front();
		}
	}
	
	q.clear();
	printf("\n");
	for(int i=1;i<=n;i++){
		while(!p.empty()&&p.back()>num[i])
			p.pop_back();
		p.push_back(num[i]);
		if(i>=k){
			printf("%d ",p.front());
			p.pop_front();
		}
	}
	return 0;
}

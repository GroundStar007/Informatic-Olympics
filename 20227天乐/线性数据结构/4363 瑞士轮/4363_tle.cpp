/*
利用优先队列(堆)
复杂度：
r*(2*n)*堆本身的log(2*n)
=50*2*10^5*log(2*10^5)
~10^8
TLE 
*/
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=100010;
int n,r,q,s[2*maxn],w[2*maxn];
struct node{
	int no;		//编号
	bool operator<(const node x)const{
		if(s[no]!=s[x.no]) return s[no]<s[x.no];
		return no>x.no;
	} 
}cur;
priority_queue<node> pq;
int main(){
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++){
		scanf("%d",&s[i]); cur.no=i;
		pq.push(cur);
	}
	for(int i=1;i<=2*n;i++) scanf("%d",&w[i]);
	while(r--){
		for(int i=0;i<n;i++){	//n轮比赛 
			node pre=pq.top(); pq.pop();
			node last=pq.top(); pq.pop();
			if(w[pre.no]>w[last.no]) s[pre.no]++;
			else s[last.no]++;
		}
		for(int i=1;i<=2*n;i++){
			cur.no=i; pq.push(cur);
		}
	}
	while(--q) pq.pop();
	printf("%d\n",pq.top().no);
}

/*
利用循环队列
维护每个单词在队列中的位置，方便查询，
若不在队列中，位置用-1表示 
*/
#include <cstdio>
const int maxm=110;
const int maxn=1010; 
int m,n,p[maxn],k,ans;
int q[maxm],head,tail;	//循环队列 
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<maxn;i++) p[i]=-1;
	scanf("%d",&k);
	head=0; tail=1%m; q[0]=k;
	p[k]=0; ans=1;
	for(int i=1;i<n;i++){
		scanf("%d",&k);
		if(p[k]==-1){
			ans++;
			if(head==tail){		//队列满 
				p[q[head]]=-1;	//队首出队
				head=(head+1)%m; 
			} 
			//k入队
			q[tail]=k; p[k]=tail;
			tail=(tail+1)%m;
		}
	}
	printf("%d\n",ans);
	return 0;
}


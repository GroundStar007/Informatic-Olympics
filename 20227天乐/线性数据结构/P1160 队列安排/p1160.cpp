#include <cstdio>
const int maxn=100010;
int n,ll[maxn],rr[maxn],m,p,d;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&p,&d);
		switch(d){
			case 0:	//i插在p的左侧 
				rr[i]=p; ll[i]=ll[p];
				rr[ll[p]]=i; ll[p]=i; break;
			case 1:	//i插在p的右侧 
			 	ll[i]=p; rr[i]=rr[p];
			 	ll[rr[p]]=i; rr[p]=i; break;
		}
	}
	//for(int i=1;i<=n;i++) printf("%d %d\n",ll[i],rr[i]);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&p);
		if(ll[p]!=-1){
			rr[ll[p]]=rr[p]; ll[rr[p]]=ll[p];
			ll[p]=-1;
		}
	}
	//for(int i=1;i<=n;i++) printf("%d %d\n",ll[i],rr[i]);
	for(p=1;ll[p];p++);
	for(;rr[p];p=rr[p]) printf("%d ",p);
	printf("%d\n",p);
	return 0;
}


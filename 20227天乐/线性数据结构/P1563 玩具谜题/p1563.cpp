/*
循环队列记录n个人
0表示面向圈内，向左对应位置减小，向右对应位置增大；
1表示面向圈外，向左对应位置增大，向右对应位置减小。 
*/
#include <cstdio>
const int maxn=100010;
int n,m,q[maxn];	//q[i]:第i个人的朝向 
int d,k;			//d:0-向左;1-向右 
char ss[maxn][15];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d%s",&q[i],ss[i]);
	int cur=0;
	for(int i=0;i<m;i++){
		scanf("%d%d",&d,&k);
		if(q[cur]==d) cur=(cur-k+n)%n;
		else cur=(cur+k)%n;
	}
	printf("%s\n",ss[cur]);
	return 0;
}

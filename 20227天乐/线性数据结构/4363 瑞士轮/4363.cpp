/*
先按初始分数排序，然后按分数高低两人一组比赛
胜者入队A，负者入队B。
这样A、B自身仍是有序的，
合并A、B是O(2*N)的
总复杂度O(r*2*N)=O(10^7) 
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100010;
int n,r,q,s[2*maxn],w[2*maxn];
int totp[2*maxn],a[maxn],b[maxn];
bool cmp(int x,int y){
	if(s[x]!=s[y]) return s[x]>s[y];
	return x<y;
}
void merge(int *tot,int *a,int *b){	//合并A、B到tot 
	int it=0,ia,ib;
	for(ia=0,ib=0;ia<n&&ib<n;){
		if(cmp(a[ia],b[ib])){
			tot[it]=a[ia]; ia++;
		}else{
			tot[it]=b[ib]; ib++;
		}
		it++;
	}
	if(ia<n){
		for(;ia<n;ia++,it++) tot[it]=a[ia];
	}
	if(ib<n){
		for(;ib<n;ib++,it++) tot[it]=b[ib];
	}
}
int main(){
	scanf("%d%d%d",&n,&r,&q);
	for(int i=1;i<=2*n;i++) scanf("%d",&s[i]);
	for(int i=1;i<=2*n;i++) scanf("%d",&w[i]);
	for(int i=0;i<2*n;i++) totp[i]=i+1;
	sort(totp,totp+2*n,cmp);
	while(r--){
		for(int i=0;i<n;i++){	//n轮比赛 totp[2*i]:totp[2*i+1]
			if(w[totp[2*i]]>w[totp[2*i+1]]){
				s[totp[2*i]]++; a[i]=totp[2*i]; b[i]=totp[2*i+1];
			}else{
				s[totp[2*i+1]]++; a[i]=totp[2*i+1]; b[i]=totp[2*i];
			}
		}
		//合并A、B到totp
		merge(totp,a,b);
	}
	printf("%d\n",totp[q-1]);
}

#include <iostream>
#include <cstdio>
using namespace std;
int min(int a,int b){return a<b?a:b;}

const int MAXLEN=100009;
const int MAX=0x7fffffff;
int n,a[MAXLEN],b[MAXLEN],mp[MAXLEN];
int dp[MAXLEN],maxn,f[MAXLEN],len; 
int l,r,mid; // 准备二分 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);mp[a[i]]=i;}
	for(int i=1;i<=n;i++){scanf("%d",&b[i]);f[i]=MAX;}
	f[0]=0;  
	for(int i=1;i<=n;i++){
		l=0,r=len;
		if(mp[b[i]]>f[len])f[++len]=mp[b[i]];
		else{
			while(l<r){
				mid=(l+r)/2;
				if(f[mid]<mp[b[i]])l=mid+1;
				else r=mid;
			}
			f[l]=min(f[l],mp[b[i]]);
		}
	}
	printf("%d",len);
	return 0;
}



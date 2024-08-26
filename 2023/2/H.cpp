#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N=1e5+10;
int T,n,a[2*N],b[2*N];
string ans;
bool f=false;

void dfs(int pos,int l,int r,string str){
	if(f)return;
	if(pos>2*n){
		bool flag=true;
		for(int i=1;i<=n*2;i++)
			if(b[i]!=b[n*2-i+1]){
				flag=false;
				break;
			}
		if(flag){
			f=true;
			ans=min(ans,str);
		}			
		return;
	}
	b[pos]=a[l];
	dfs(pos+1,l+1,r,str+'L');
	b[pos]=a[r];
	dfs(pos+1,l,r-1,str+'R');
}

int main(){
	scanf("%d",&T);
	while(T--){
		ans="Z";
		memset(b,0,sizeof(b));
		f=false;
		
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
			scanf("%d",&a[i]);
		dfs(1,1,2*n,"");
		if(f) printf("%s\n",ans.c_str());
		else printf("-1\n");
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,mine[25],cel[30][30];
int step[25],ans[25],len,len1,maxn;

void dfs(int now,int curr){
	if(!cel[now][0]&&curr>maxn){
		maxn=curr;
		for(int i=1;i<=len;i++)
			ans[i]=step[i];
		len1=len;
		return;
	}
	for(int i=now+1;i<=n;i++)
		if(cel[now][i]){
			step[++len]=i;
			dfs(i,curr+mine[i]);
			step[len--]=0;
		}
}

int main(){
	freopen("mine.in","r",stdin);
	freopen("mine.out","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>mine[i];
	for(int i=1;i<n;i++){
		cel[i][0]=0;
		for(int j=i+1;j<=n;j++){
			cin>>cel[i][j];
			if(cel[i][j])cel[i][0]=1;
		}
	}
	for(int i=1;i<=n;i++){
		step[++len]=i;
		dfs(i,mine[i]);
		step[len--]=0;
	}
	for(int i=1;i<=len1;i++)cout<<ans[i]<<" ";
	cout<<endl<<maxn;
	return 0;
} 

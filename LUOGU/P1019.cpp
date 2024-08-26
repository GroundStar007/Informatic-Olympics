#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,vis[29],ans;
string word[29];

inline int find(string a,string b){  // 求最小重合长度 
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]==b[0]){
			int k=i,j=0,l=0;
			while(j<b.size()&&k<a.size()){
				if(a[k++]==b[j++])l++;
				else return 0;
			}
			if(k==a.size()&&j<b.size())return l;
			else return 0;
		}	
	}
	return 0;
}

void dfs(int x,int len){
	ans=max(ans,len);
	for(int i=0;i<n;i++){
		int r=find(word[x],word[i]);
		if(!r||vis[i]==2)continue;
		vis[i]++;
		dfs(i,len+word[i].size()-r);
		vis[i]--;
	}
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    	cin>>word[i];
    cin>>word[n];
	dfs(n,0);		
    printf("%d",ans+1);  // 加上开头字母 
    return 0;
}


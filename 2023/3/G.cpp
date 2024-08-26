#include <iostream>
#include <cstdio>
#include <cmath>
#include <unordered_map>
using namespace std;

int T,n,num[50009];
unordered_map<int,int>mp;

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
			mp[num[i]]=1;
		}
		for(int i=1;i<=n;i++)
			if(mp[num[i]]!=0){
				printf("%d ",num[i]);
				mp[num[i]]--;
			}
		printf("\n");
	}
	return 0;
}

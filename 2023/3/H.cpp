#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;

int n,Q,m,p[100009];
unordered_map<int,int>mp;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		mp[p[i]]=i;
	}
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&m);
		printf("%d\n",mp[m]);
	}
	return 0;
}

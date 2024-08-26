#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,num[10]={1},k,m;

void print(int k){
	for(int i=1;i<k;i++)
		cout<<num[i]<<"+";
	cout<<num[k]<<endl;
}

inline void dfs(int x){
	for(int i=num[x-1];i<=m;i++){
		if(i==n)continue;
		num[x]=i;
		m-=i;
		if(!m)print(x);
		else dfs(x+1);
		m+=i; 
	}
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    m=n;
    dfs(1);
    return 0;
}


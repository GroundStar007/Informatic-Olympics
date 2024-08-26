#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m,a,b[2000009];
int cnt; 

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		b[++cnt]=a;
	} 
	while(m--){
		scanf("%d",&a);
		printf("%d\n",b[a]);
	}
	return 0;
} 

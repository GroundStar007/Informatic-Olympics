#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int n,num[10009],x[10009];
int s[10009],head;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	for(int i=n;i>=1;i--){
		while(head>0&&num[s[head]]<=num[i])
			head--;
		x[s[head]]=num[i];
		s[++head]=i;
	}
	for(int i=1;i<=n;i++)printf("%d ",x[i]);
	return 0;
}







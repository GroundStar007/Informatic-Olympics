#include <iostream>
#include <cstdio>
using namespace std;
int n,q,n1[1009],q3,q4,a=10000009,e=1;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%d",&n1[i]);
	for(int i=0;i<q;i++){
		a=10000009;e=1;
		scanf("%d%d",&q3,&q4);
		for(int f=0;f<q3;f++)e*=10;
		for(int j=0;j<n;j++)
			if(n1[j]%e==q4&&n1[j]<a)a=n1[j];
		if(a!=10000009)printf("%d\n",a);	
		else  printf("-1\n");
	}
}

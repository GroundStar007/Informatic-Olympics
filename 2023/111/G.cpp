#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,num,t[3009];
int main(){
	freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		if(num>=0)t[num]++;
		else t[abs(num)+1000]++;
	}
	for(int i=2009;i>=1001;i--)
		if(t[i]!=0)
			while(t[i]--)
				cout<<"-"<<i-1000<<" ";
	for(int i=0;i<=1000;i++)
		if(t[i]!=0)
			while(t[i]--)
				cout<<i<<" ";
	return 0;
}

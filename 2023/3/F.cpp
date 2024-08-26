#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;

int n,h[1009],lenth=0,ans;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	for(int i=0;i<n;i++){
		lenth=0;
		for(int j=i+1;j<n&&h[j]>=h[i];j++,lenth++);
		for(int j=i-1;j>=0&&h[j]>=h[i];j--,lenth++);
		ans=max(ans,(lenth+1)*h[i]);
	}
	printf("%d",ans);
	return 0;
}

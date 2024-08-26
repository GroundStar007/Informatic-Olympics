#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;

const int N=200009;
int T,n,a[N],t1,t2;
deque<int>ql,qr;

void check(){
	
}

int main(){
	scanf("%d",&T);
	while(T--){
		ql.clear();
		qr.clear();
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)scanf("%d",&a[i]);
		int m1=a[1],m2=a[n*2];
		for(int i=1;i<=n;i++)
			if(a[i]==m1)
	}
	return 0;
}

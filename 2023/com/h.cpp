#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int num[6],k;
	scanf("%d",&k);
	for(int i=10000;i<=30000;i++){
		int n=i,cnt=5;
		while(n)num[cnt--]=n%10,n/=10;
		int a=num[1]*100+num[2]*10+num[3];
		int b=num[2]*100+num[3]*10+num[4];
		int c=num[3]*100+num[4]*10+num[5];
		if(a%k==0&&b%k==0&&c%k==0){
			printf("%d\n",i);
		}
	}
	return 0;
}

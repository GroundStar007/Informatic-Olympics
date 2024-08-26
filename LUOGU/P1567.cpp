#include<bits/stdc++.h>  
using namespace std;  
int a[2];  
int main(){  
	int n,x,num;  
	num=0;x=0;
   	cin>>n;
   	for(int i=1;i<=n;i++){
   		cin>>a[1];
   		if(a[1]>=a[0])
			x++,num=max(num,x);
		else x=1;
		a[0]=a[1];
	}
    cout<<num;
   	return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int n,m,nlen,k,l[100];
long long t;
char num[100]; 

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d\n%s%d",&n,num,&m);
    nlen=strlen(num);
    for(int i=nlen-1;i>=0;i--){
    	if(num[i]>='0'&&num[i]<='9')
    		t+=(num[i]-'0')*pow(n,(nlen-i-1)*1.0);
    	if(num[i]>='A'&&num[i]<='F')
    		t+=(num[i]-'A'+10)*pow(n,(nlen-i-1)*1.0);
	}
	while(t!=0){
		l[k++]=t%m;
		t/=m;	
	}
	for(int i=k-1;i>=0;i--){
		if(l[i]>=10)printf("%c",'A'+l[i]-10);
		else printf("%d",l[i]); 
	} 
    return 0;
}


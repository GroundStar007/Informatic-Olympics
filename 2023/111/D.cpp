#include <iostream> 
#include <cstdio>
#include <cstring>
using namespace std;

int T,n,num[1000009],t;
int a[]={1,-1},f=0,ff;
string s,L="L",R="R";

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		s="";	
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
	
		int l=0,r=n-1;
		while(r>=l){
			t+=a[f];
			if(num[l]==t)l++,s+=L;
			else if(num[r]==t)r--,s+=R;
			else{
				printf("-1\n");
				return 0;
			}
			if(t==n) f=1;
		}
		cout<<s<<endl;
	}
	return 0;
}

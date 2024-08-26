#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char w[109];
int k[109];
int len;

int main(){
	freopen("1.txt","r",stdin);
	cin.getline(w,101);
	len=strlen(w);
	for(int i=0;i<len;i++){
		if(w[i]==')'){
			for(int j=i-1;j>=0;j--)
				if(!k[j]&&(w[j]=='['||w[j]=='(')){
					if(w[j]=='(')k[j]=k[i]=1;
					break;
				}
		}
		if(w[i]==']'){
			for(int j=i-1;j>=0;j--)
				if(!k[j]&&(w[j]=='['||w[j]=='(')){
					if(w[j]=='[')k[j]=k[i]=1;
					break;
				}	
		}
	}
	
	for(int i=0;i<len;i++){
		if(!k[i]){
			cout<<w[i];
			if(w[i]=='(')cout<<')';
			if(w[i]==')')cout<<'(';
			if(w[i]=='[')cout<<']';
			if(w[i]==']')cout<<'[';
		}
		else cout<<w[i];
	}
} 


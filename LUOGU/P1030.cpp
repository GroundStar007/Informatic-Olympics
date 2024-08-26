#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string in,post;
int p;

void preOrder(int lin,int rin,int lpost,int rpost){
	printf("%c",post[rpost-1]);
	p=in.find(post[rpost-1]);
	if(p>lin)preOrder(lin,p,lpost,lpost+p-lin);
	if(p+1<rin)preOrder(p+1,rin,lpost+p-lin,rpost-1);
}

int main(){
	freopen("1.txt","r",stdin);
	cin>>in>>post;
	preOrder(0,in.size(),0,post.size());
	return 0;
} 



#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
stack<int>s;
int n,num[100009],l[100009];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	for(int i=1;i<=n;i++){
		while(!s.empty()&&num[s.top()]<=num[i])
			s.pop();
		l[i]=s.empty()?-1:num[s.top()];
		s.push(i);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",l[i]);	
	return 0;
}

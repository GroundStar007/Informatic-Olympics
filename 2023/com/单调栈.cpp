#include <iostream>
#include <cstdio>
using namespace std;
const int N=3000009;
int n,a[N],f[N];
struct Stack{
	int s[N],head=0;
	int top(){return s[head];}
	void push(int x){s[++head]=x;}
	bool empty(){return head==0;}
	void pop(){head--;}
}s;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		while(!s.empty()&&a[s.top()]<=a[i])s.pop();
		s.push(i);
		f[i]=!s.empty()?i:0;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",f[i]);
	return 0;
}

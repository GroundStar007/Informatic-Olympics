#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;

int n,a[100009],l[100009],ans;
stack<int>s;

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++){
		while(s.size()&&s.top()<=a[i])
			s.pop();
		if(!s.empty())ans+=s.size();
		s.push(a[i]);
	}
	printf("%d",ans);
	return 0;
};

#include<bits/stdc++.h>
using namespace std;
int n,k;
queue<int> q;
int main(){
  cin>>n>>k;
  for(int i=1;i<=n;i++)q.push(i);
  while(q.size()){
  	for(int i=1;i<k;i++){
  	  q.push(q.front());
  	  q.pop();
	}
	printf("%d ",q.front());
	q.pop();
  }
return 0;
}

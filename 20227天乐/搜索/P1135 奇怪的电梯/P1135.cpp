#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,a,b,k[210],vis[210]; 
struct Node{
  int to,step;
}node,nextnode;
queue<Node>q;
int main(){
  cin>>n>>a>>b;
  for(int i=1;i<=n;i++)	cin>>k[i];
  int t1,flag=0;
  node.to=a;
  node.step=0;
  q.push(node);
  vis[node.to]=1;
  while(!q.empty()){
  	node=q.front();
  	q.pop();
  	if(node.to==b){
  		cout<<node.step<<endl;
  		flag=1;
  		break;
  	}
  	t1=node.to+k[node.to];//向上走
	if(t1<=n&&!vis[t1]) {
	  vis[t1]=1;
	  nextnode.to=t1;
	  nextnode.step=node.step+1;
	  q.push(nextnode);
	}
	t1=node.to-k[node.to];//向下走 
	if(t1>=1&&!vis[t1]){
	  vis[t1]=1;
	  nextnode.to=t1;
	  nextnode.step=node.step+1;
	  q.push(nextnode);
	}
  }
  if(!flag)cout<<"-1"<<endl;
  return 0;
}

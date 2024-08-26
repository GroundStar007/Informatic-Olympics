#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
struct node{int x,y,num;};
struct cmp1{
	bool operator()(node a,node b){
		return a.num>b.num;
	}
};
priority_queue<node,vector<node>,cmp1>ski;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
node l;
int r,c,h[109][109],dp[109][109],xx,yy,maxn=-1;

int main(){
    freopen("1.txt","r",stdin);
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    	for(int j=1;j<=c;j++){
    		cin>>h[i][j];
    		ski.push((node){i,j,h[i][j]});
    		dp[i][j]=1;
		}
    while(ski.size()){
    	l=ski.top();
    	ski.pop();
    	for(int i=0;i<4;i++){
			xx=l.x+dx[i],yy=l.y+dy[i];
			if(h[xx][yy]<l.num)
				dp[l.x][l.y]=max(dp[l.x][l.y],dp[xx][yy]+1);
				maxn=max(maxn,dp[l.x][l.y]);
		} 
	} 
	cout<<maxn;
    return 0;
}

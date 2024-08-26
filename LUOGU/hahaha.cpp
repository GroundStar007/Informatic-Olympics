#include<iostream>
#include<queue>
using namespace std;
struct node{
    int i,j,num,f;
};//结构体存点
struct cmp1{
    bool operator()(node x,node y){
        return x.num>y.num;
    }
};//优先队列小的在前面
priority_queue<node,vector<node>,cmp1>q;//stl大法好
int n,m,maxn,maxj,maxi,w,top=0,g[101][101],f[101][101];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        	f[i][j]=1;//长度最开始为1，它自己
            cin>>g[i][j];
            node a;
            a.i=i;a.j=j;a.f=0;a.num=g[i][j];
            q.push(a);//入队
        }
    }
    while(!q.empty()){
        node now1=q.top();//取点
        int i=now1.i;
        int j=now1.j;//坐标
        int now=now1.num;//此点的权值
        q.pop();//出队
        if(g[i-1][j]<now) f[i][j]=max(f[i][j],f[i-1][j]+1);
            if(g[i+1][j]<now) f[i][j]=max(f[i][j],f[i+1][j]+1);
            if(g[i][j-1]<now) f[i][j]=max(f[i][j],f[i][j-1]+1);
            if(g[i][j+1]<now) f[i][j]=max(f[i][j],f[i][j+1]+1);//dp
            if(maxn<f[i][j]) maxn=f[i][j];//取最大值
    }
    cout<<maxn;//输出
    return 0;//第一篇题解，请多支持！
}

#include<iostream>
#include<queue>
using namespace std;
struct node{
    int i,j,num,f;
};//�ṹ����
struct cmp1{
    bool operator()(node x,node y){
        return x.num>y.num;
    }
};//���ȶ���С����ǰ��
priority_queue<node,vector<node>,cmp1>q;//stl�󷨺�
int n,m,maxn,maxj,maxi,w,top=0,g[101][101],f[101][101];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        	f[i][j]=1;//�����ʼΪ1�����Լ�
            cin>>g[i][j];
            node a;
            a.i=i;a.j=j;a.f=0;a.num=g[i][j];
            q.push(a);//���
        }
    }
    while(!q.empty()){
        node now1=q.top();//ȡ��
        int i=now1.i;
        int j=now1.j;//����
        int now=now1.num;//�˵��Ȩֵ
        q.pop();//����
        if(g[i-1][j]<now) f[i][j]=max(f[i][j],f[i-1][j]+1);
            if(g[i+1][j]<now) f[i][j]=max(f[i][j],f[i+1][j]+1);
            if(g[i][j-1]<now) f[i][j]=max(f[i][j],f[i][j-1]+1);
            if(g[i][j+1]<now) f[i][j]=max(f[i][j],f[i][j+1]+1);//dp
            if(maxn<f[i][j]) maxn=f[i][j];//ȡ���ֵ
    }
    cout<<maxn;//���
    return 0;//��һƪ��⣬���֧�֣�
}

#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXN 200
#define INF 1e9
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;

int n,x[MAXN],y[MAXN]; // ��¼������x,y���� 
int f[MAXN],a;  // f[]��¼��ͬ����������ͨ�� 
double MaxSp[MAXN],  // MaxSp[i]��¼ÿ����ͨ����i�������� ���·�����ֵ 
	m[MAXN][MAXN];  //  m[][]��¼����֮����� 
double MinDis=INF,  //  ����¼ʹ 
	MaxDis,
	d[MAXN];  // ÿ����ͨ���ֱ�� (���·�����ֵ

inline void dfs(int i,int id){  // dfs����ͨ�� 
	f[i]=id;
	for(int j=1;j<=n;j++)	
		if(m[i][j]<INF*1.0&&!f[j])
			dfs(j,id);
}

inline double Distance(int k,int h){  // ŷ����þ��� 
	return sqrt((x[k]-x[h])*(x[k]-x[h])+(y[k]-y[h])*(y[k]-y[h]))*1.0;
}

int main(){
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%1d",&a);
			if(a==1||i==j)m[i][j]=Distance(i,j);
			else m[i][j]=INF*1.0;
		}

	int id=1;
	for(int i=1;i<=n;i++)
		if(!f[i])dfs(i,id++);// dfsȾɫ��ͨ��

	for(int k=1;k<=n;k++)// Floyd
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
	
	for(int i=1;i<=n;i++)// ����ÿ�������У�ÿ�������㵽������� ���· �����ֵ��
		for(int j=1;j<=n;j++){//����ÿ�������У��������·�����ֵ����ÿ��������ֱ����
			if(m[i][j]<INF*1.0)
				MaxSp[i]=max(MaxSp[i],m[i][j]);
			d[f[i]]=max(d[f[i]],MaxSp[i]);
		} 

	for(int i=1;i<=n;i++)	// �Ҵ�
		for(int j=1;j<=n;j++)
			if(f[i]!=f[j]){
				// ���� A ���������·�����ֵ������ B ���������·�����ֵ���ӱߺ�ͨ�������ߵ����·�����ֵ 
				// ����ȡ��� 
				MaxDis=max(max(d[f[i]],d[f[j]]),MaxSp[i]+Distance(i,j)+MaxSp[j]);
				MinDis=min(MinDis,MaxDis);
			}
	printf("%.6lf",MinDis);
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,s[4][30],vis[30],num[30];
char l;

inline void dfs(int x,int y,int t){  // x,y�������꣬t������һ�е���ǰ�еĽ�λ 
	for(int i=1;i<=n;i++){  // ��֦ 
		if(num[s[1][i]]!=-1&&num[s[2][i]]!=-1&&num[s[3][i]]!=-1)  // �������������ȷ��
		// ����a+b=c����(a+b)%n=c (n����) 
		// ���н�λʱ��a+b+1=c, ����(a+b+1)%n=c (n����) 
			if((num[s[1][i]]+num[s[2][i]])%n!=num[s[3][i]]%n&& // ����λ 
				((num[s[1][i]]+num[s[2][i]]+1)%n!=num[s[3][i]]%n))
				return;  // ǰ����ȷ���������Ͼͼ��� 
	}
	if(y>n){  // �������� 
		if(!t)  // ���λ�������н�λ�����򲻿�����nλ�� 
			for(int i=0;i<n;i++)  // ��� 
				printf("%d ",num[i]);
		return;
	}
	int z=s[x][y];
	if(x<=2){  // ��ǰ���� 
		if(num[z]!=-1)dfs(x+1,y,t);  // ��ȷ����ֱ������һ�� 
		else  // ��ȷ�� 
			for(int i=0;i<n;i++)
				if(!vis[i]){
					vis[i]=1;
					num[z]=i;
					dfs(x+1,y,t);  // ��һ�� 
					vis[i]=0;
					num[z]=-1;  // ���� 
				}
	}
	else{
		t=t+num[s[1][y]]+num[s[2][y]];
		if(num[z]!=-1&&num[z]==t%n)  // a+b+t=c  ((a+b+t)%n==c)n 
			dfs(1,y+1,t/n);  // ����һλ 
		if(num[z]==-1&&!vis[t%n]){
			vis[t%n]=1;
			num[z]=t%n;
			dfs(1,y+1,t/n);  // ��һ�� 
			vis[t%n]=0;
			num[z]=-1;  // ���� 
		}
	}
}

int main(){
	freopen("1.txt","r",stdin);
	memset(num,-1,sizeof(num));  // ��ʼ�� 
	scanf("%d\n",&n);
	for(int i=1;i<=3;i++)
		for(int j=n;j>=1;j--){
			cin>>l;
			s[i][j]=l-'A';
		}
	dfs(1,1,0);   
	return 0;
}

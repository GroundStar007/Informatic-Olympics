#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,s[4][30],vis[30],num[30];
char l;

inline void dfs(int x,int y,int t){  // x,y代表坐标，t代表上一列到当前列的进位 
	for(int i=1;i<=n;i++){  // 剪枝 
		if(num[s[1][i]]!=-1&&num[s[2][i]]!=-1&&num[s[3][i]]!=-1)  // 如果三个数都已确定
		// 对于a+b=c，有(a+b)%n=c (n进制) 
		// 当有进位时，a+b+1=c, 则有(a+b+1)%n=c (n进制) 
			if((num[s[1][i]]+num[s[2][i]])%n!=num[s[3][i]]%n&& // 不进位 
				((num[s[1][i]]+num[s[2][i]]+1)%n!=num[s[3][i]]%n))
				return;  // 前面已确定，不符合就剪掉 
	}
	if(y>n){  // 搜索结束 
		if(!t)  // 最高位不能再有进位，否则不可能是n位数 
			for(int i=0;i<n;i++)  // 输出 
				printf("%d ",num[i]);
		return;
	}
	int z=s[x][y];
	if(x<=2){  // 是前两行 
		if(num[z]!=-1)dfs(x+1,y,t);  // 已确定，直接搜下一行 
		else  // 不确定 
			for(int i=0;i<n;i++)
				if(!vis[i]){
					vis[i]=1;
					num[z]=i;
					dfs(x+1,y,t);  // 下一行 
					vis[i]=0;
					num[z]=-1;  // 回溯 
				}
	}
	else{
		t=t+num[s[1][y]]+num[s[2][y]];
		if(num[z]!=-1&&num[z]==t%n)  // a+b+t=c  ((a+b+t)%n==c)n 
			dfs(1,y+1,t/n);  // 搜下一位 
		if(num[z]==-1&&!vis[t%n]){
			vis[t%n]=1;
			num[z]=t%n;
			dfs(1,y+1,t/n);  // 下一列 
			vis[t%n]=0;
			num[z]=-1;  // 回溯 
		}
	}
}

int main(){
	freopen("1.txt","r",stdin);
	memset(num,-1,sizeof(num));  // 初始化 
	scanf("%d\n",&n);
	for(int i=1;i<=3;i++)
		for(int j=n;j>=1;j--){
			cin>>l;
			s[i][j]=l-'A';
		}
	dfs(1,1,0);   
	return 0;
}

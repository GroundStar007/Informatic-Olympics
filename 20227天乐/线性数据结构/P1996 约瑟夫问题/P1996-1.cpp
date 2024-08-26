//数组模拟链表 
#include<iostream>
using namespace std;
int next[1000005];
int main(){
    int n,m;
    cin>>n>>m;//输入n、m
    for(int i=0;i<n;i++)//初始化
    	next[i]=i+1;
	next[n]=1;
	int p=0;
	for(int i=1;i<=n;i++){//开始模拟出圈过程
		for(int j=1;j<m;j++)
			p=next[p];//p位置右移
		cout<<p[next]<<" ";//输出出圈人的位置
		next[p]=next[next[p]];//删掉出圈人
	}
	return 0;
}

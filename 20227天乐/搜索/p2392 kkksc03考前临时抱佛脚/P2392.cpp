#include<bits/stdc++.h>
using namespace std;
int Left,Right,minn,ans;//左脑，右脑，最小值，所求值
int s[5];//每个科目的题目数
int a[21];//每个题目花费的时间
void search(int x,int y){
  if(x>s[y]){
  	minn=min(minn,max(Left,Right));
  	return;
  }
  Left+=a[x];//把此题加到左脑
  search(x+1,y);//继续安排下一题
  Left-=a[x];//把此题退出左脑
  Right+=a[x];//把此题加到右脑
  search(x+1,y);//继续安排下一题
  Right-=a[x];//把此题退出右脑
}
int main(){
  for(int i=1;i<=4;i++)cin>>s[i];
  for(int i=1;i<=4;i++){
  	Left=Right=0;
  	minn=1e9;
  	for(int j=1;j<=s[i];j++)cin>>a[j];
  	search(1,i);//从第i个科目的第一道题开始搜索
	ans+=minn; 
  }
  cout<<ans<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int Left,Right,minn,ans;//���ԣ����ԣ���Сֵ������ֵ
int s[5];//ÿ����Ŀ����Ŀ��
int a[21];//ÿ����Ŀ���ѵ�ʱ��
void search(int x,int y){
  if(x>s[y]){
  	minn=min(minn,max(Left,Right));
  	return;
  }
  Left+=a[x];//�Ѵ���ӵ�����
  search(x+1,y);//����������һ��
  Left-=a[x];//�Ѵ����˳�����
  Right+=a[x];//�Ѵ���ӵ�����
  search(x+1,y);//����������һ��
  Right-=a[x];//�Ѵ����˳�����
}
int main(){
  for(int i=1;i<=4;i++)cin>>s[i];
  for(int i=1;i<=4;i++){
  	Left=Right=0;
  	minn=1e9;
  	for(int j=1;j<=s[i];j++)cin>>a[j];
  	search(1,i);//�ӵ�i����Ŀ�ĵ�һ���⿪ʼ����
	ans+=minn; 
  }
  cout<<ans<<endl;
  return 0;
}

//�ֹ�ջ 
#include<bits/stdc++.h>
using namespace std;
char st[1009],a[1009];
int main(){
  scanf("%s",a);
  int mid,nxt,len=strlen(a);
  mid=len/2;
  if(len%2==1)nxt=mid+1;
  else nxt=mid;
  int top=0;//ջ�ĳ�ʼ��
  for(int i=0; i<mid; i++)
	st[++top]=a[i];
  for(int i=nxt; i<len; i++) {//��ʼƥ��
	if(a[i]==st[top])--top;
	else break;
  }	
  if(top!=0)printf("no");
  else printf("yes");
return 0;
}



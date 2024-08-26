//STLջ
#include<bits/stdc++.h> 
using namespace std;
stack<char>s;
char a[1009];
int main(){
 scanf("%s",a);
 int mid,nxt,len=strlen(a);
 mid=len/2;
 if(len%2==1)nxt=mid+1;
 else nxt=mid;
 for(int i=0;i<mid;i++)s.push(a[i]);
 for(int i=nxt;i<len;i++){
 	if(a[i]!=s.top())break;
 	s.pop();
	}
  cout<<s.top()<<endl;
 if(s.empty())printf("yes");
 else printf("no");
 return 0;
}

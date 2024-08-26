#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
struct node{
	string str;
	int step;
};
string a,b;
string org[maxn],tra[maxn];
int n,ans;
map<string,int>ma;
string trans(string str,int i,int j){
   string ans="";
   if(i+org[j].length()>str.length())return ans;
   for(int k=0;k<org[j].length();k++)
     if(str[i+k]!=org[j][k])return ans;
   ans=str.substr(0,i);
   ans+=tra[j];
   ans+=str.substr(i+org[j].length());
   return ans;
}
void bfs(){
  queue<node>q;
  node s;
  s.str=a;
  s.step=0;
  q.push(s);
  while(!q.empty()){
  	 node u=q.front();
  	 q.pop();
  	 if(ma.count(u.str)==1)continue;//����ִ˷������ֹ�������
  	 if(u.str==b){
  	    ans=u.step;
  	    break;
	 }
	 ma[u.str]=1;
	 for(int i=0;i<u.str.length();i++)//ö�ٵ�ǰ�������п���λ��
	   for(int j=0;j<n;j++){//ö�����п��ܵı任����
	     string temp=trans(u.str,i,j);
	     if(temp!=""){
	     	node v;
	     	v.str=temp;
	     	v.step=u.step+1;
	     	q.push(v);
		 }
	   }
  }
    if (ans > 10 || ans == 0)
        cout << "NO ANSWER!" << endl;
    else
        cout << ans << endl;
}
int main(){
   cin>>a>>b;
   while(cin>>org[n]>>tra[n])n++;
   bfs();
   return 0;
}

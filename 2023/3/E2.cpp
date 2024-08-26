#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

int s,l,p[1000009],cnt=0;
string n,str;
stack<int>st;

int main(){
	cin>>n>>s;
	l=n.size();
	for(int i=0;i<n.size();i++){
		while(s>0&&!st.empty()&&n[st.top()]>n[i]){
			p[st.top()]++;
			st.pop();
			s--;
		}
		st.push(i);
	}
	for(int i=0;i<n.size();i++)
		if(p[i]!=0)continue;
		else cout<<n[i];
	return 0;
}

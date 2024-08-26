#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
map<string,string>mp;
int n,m;
string s,ID;
int main(){
	freopen("1.txt","r",stdin);
	scanf("%d%d\n",&n,&m);
	while(n--){
		cin>>ID>>s;
//		cout<<ID<<" "<<s<<endl;
		mp[ID]=s;
	}
	while(m--){
		cin>>ID;
//		cout<<ID<<endl;
		if(mp[ID]=="")cout<<"no find"<<endl;
		else cout<<mp[ID]<<endl;
	}
	return 0;
}

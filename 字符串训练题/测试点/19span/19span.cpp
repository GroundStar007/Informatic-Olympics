#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
string s,s1,s2 ;
int l1,l2,l;
int main() {
	freopen("span5.in","r",stdin);
	freopen("span5.out","w",stdout);
    getline(cin,s,',');
    getline(cin,s1,',');
    getline(cin,s2);
    l1=s.find(s1);
    l2=s.rfind(s2);
    l=s1.length();
    if(l2<l1||l2==-1||l1==-1)cout<<-1;
    else cout<<l2-l1-l;
    return 0;
}


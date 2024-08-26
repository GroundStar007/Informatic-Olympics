#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
struct queue{
	vector<string>v;
	void push(string s){v.push_back(s);}
	void pop(){v.erase(v.begin());}
	bool empty(){return v.empty();}
	bool size(){return v.size();}
	string front(){return v[0];}
	void clear(){v.clear();}
}q;
string A,B,x,y,origin[10],translation[10];
int cnt;
map<string,int>mp;
map<string,int>steps;
string Translate(int i, string k,int m){
    string t=translation[i], o=origin[i];
    int len=k.length(),len1=o.length();
    if(m+len1>len)return "";
    for(int a=0;a<o.length();a++)
        if(k[m+a]!=o[a])return "";
    return k.substr(0,m)+t+k.substr(m+len1);
}
int main(){
	cin>>A>>B;
    for(;cin>>x>>y;cnt++)origin[cnt]=x,translation[cnt]=y;
    q.push(A),steps[A]=0;
    int ans=-1;
    while(!q.empty()){
        string k=q.front();
        q.pop();
        int len=k.length();
        if(mp.count(k)==1)continue;
        mp[k]=1;
        if(k==B){ans=steps[k];break;}
        for(int i=0;i<cnt;i++){
            for(int j=0;j<k.length();j++){
                x=Translate(i,k,j);
                if(x=="")continue;
                steps[x]=steps[k]+1,q.push(x);
            }
        }
    }
    if(ans==-1||ans>10) cout<<"NO ANSWER!";
    else cout<<ans;
	return 0;
}

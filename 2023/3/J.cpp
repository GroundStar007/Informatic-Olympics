#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int n;
long long a,b,c,d,e;
string op,ad;
map<string,int>mp;

bool check(string k){
	int c1=0,c2=0,c3=0;  // .  :  num
	long long num=0;
	for(int i=0;i<k.size();i++){
		if((!i||k[i-1]=='.'||k[i-1]==':')&&k[i]>='0'&&k[i]<='9')
			c3++;
		if(k[i]=='.'||k[i]==':'){
			if(k[i]=='.')c1++;
			if(k[i]==':')c2++;
			if(c1<3&&c2)return false;
			if(k[i-1]=='.'|k[i-1]==':')return false;
			if(!c3)return false;
			if(c3<5&&(num<0||num>255))return false;
			num=0;
		}
		else if(!num&&i&&k[i-1]=='0')return false;
		else num=num*10+k[i]-'0';
	}
	if(c1!=3||c2!=1||num<0||num>65535||c3!=5)
		return false;
	return true;
}

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		cin>>op>>ad;
		if(check(ad)==false){
			printf("ERR\n");
			continue;
		}
		if(op=="Server"){
			if(mp[ad]>0)printf("FAIL\n");
			else if(mp[ad]==0){
				mp[ad]=i;
				printf("OK\n");
			} 
		}
		else if(op=="Client"){
			if(mp[ad]) printf("%d\n",mp[ad]);
			else printf("FALL\n");
		}
	}
	return 0;
}

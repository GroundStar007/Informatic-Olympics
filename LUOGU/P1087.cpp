#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int n,cnt;
char t[1030];

inline void dfs(int s,int e){
	if(s<e){
		dfs(s,(s+e)/2);
		dfs((s+e)/2+1,e);
	}
	bool o=false,z=false;
	for(int i=s;i<=e;i++){
		int k=(int)t[i]-'0';
		if(k)o=true;
		if(!k)z=true;
	}
	if(o&&z)printf("%c",'F');
	if(!o&&z)printf("%c",'B');
	if(o&&!z)printf("%c",'I');
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d\n",&n);
    int g=pow(2,n*1.0);
    cin.getline(t,g+1);
    dfs(0,g-1);
    return 0;
}



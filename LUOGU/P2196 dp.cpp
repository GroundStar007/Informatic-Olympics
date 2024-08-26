#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,mine[25],cel[30][30];

int main(){
	freopen("1.txt","r",stdin);
	memset(cel,63,sizeof(cel));
	cin>>n;
	for(int i=1;i<=n;i++)cin>>mine[i];
	for(int i=1;i<n;i++){
		cel[i][0]=0;
		for(int j=i+1;j<=n;j++){
			cin>>m;
			if(m)cel[i][j]=cel[i][0]=1;
		}
	}
} 

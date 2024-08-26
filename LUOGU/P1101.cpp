#include <iostream>
#include <cstdio>
using namespace std;

int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
int n,s[109][109];
char word[109][109],w[10]="yizhong";
bool flag=false;

inline int search(int x,int y,int tox,int toy,int p){
	if(x<0||x>n-1||y<0||y>n-1)return 0;
	if(p==7){
		s[x][y]=1;
		return 1;
	}
	if(word[x][y]!=w[p])return 0;
	if(search(x+tox,y+toy,tox,toy,p+1)==1
		&&word[x+tox][y+toy]==w[p]){
		s[x][y]=1;
		return 1;
	}
	return 0;
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    	cin.getline(word[i],101);
    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(word[i][j]=='y')
				for(int i=0;i<8;i++){
					int xx=i+dx[i],yy=j+dy[i];
					if(search(xx,yy,dx[i],dy[i],0))
						s[i][j]=1;
				}
	
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++)
    		cout<<s[i][j]<<" ";
    	cout<<endl;
	}
    return 0;
}


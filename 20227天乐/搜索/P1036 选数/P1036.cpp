#include<iostream>
#include<cmath>
using namespace std;
int a[21],n,k,total=0;
bool vis[21];
bool prime(int x){
    if(x==0||x==1)return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return false;
    return true;
}
void dfs(int cur,int cnt,int s){
	//1..cur中，选了cnt个数，和是s 
	if(cnt==k){
		if(prime(s))total++;
		return;
	}
    for(int i=cur+1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
			dfs(i,cnt+1,s+a[i]);
            vis[i]=0;
        }
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(0,0,0);
    cout<<total;
    return 0;
}


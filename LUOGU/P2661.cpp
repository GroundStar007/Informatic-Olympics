#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n,k,into[200009][2],h,minn=0x7fffffff;
//  into[i][0]����i�����  [1]�����Ƿ��ڻ��ڣ�0��1���� 
vector<int>peo[200009];
queue<int>q;

int dfs(int start,int now,int steps){
	if(now==start&&steps){
		return 0;
	}
	
	for(int i=0;i<peo[now].size();i++){
		if(!into[peo[now][i]][1]){
			return dfs(start,peo[now][i],steps+1)+1;
		}
	}
}

void toposort(){
	for(int i=1;i<=n;i++){
		if(!into[i][0]&&!into[i][1]){
			q.push(i);  // ��� 
			into[i][1]=1;  // ��ǲ��ڻ��� 
		}
	}
	while(!q.empty()){
		int l=q.front(); // ���� 
		q.pop();
		for(int i=0;i<peo[l].size();i++){
			// ʹ���������Ԫ�������Ľڵ����-1 
			if(!--into[peo[l][i]][0]&&!into[peo[l][i]][1]){
				q.push(peo[l][i]);
				into[peo[l][i]][1]=1;
			}	
		}	
	}
}

int main(){
	freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		peo[i].push_back(k);
		into[k][0]++;
	}
	toposort();
//	for(int i=1;i<=n;i++)
//		if(!into[i][1])cout<<i<<" "; 
	for(int i=1;i<=n;i++){
		if(!into[i][1])
		minn=min(minn,dfs(i,i,0));
	} 
	printf("%d",minn);
	return 0;
}

//  ��ʱ������ 

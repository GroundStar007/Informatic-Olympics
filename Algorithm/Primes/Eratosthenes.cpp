#include <iostream>
#include <cstdio>
#define MAXN 0x7fff
using namespace std;
int h[MAXN],n;
int main(){
    cin>>n;
    h[0]=h[1]=1;
    for(int i=2;i<=n/i;i++){
		if(h[i]==0){
        	for(int j=i*i;j<=n;j+=i)
			    h[j]=1; // j是i的一个倍数，j是合数，筛掉。
		}
	}
    if(!h[n])cout<<"True";
    else cout<<"False";
    return 0;
}

// 埃拉托色尼筛

#include <iostream>
#include <cstdio>
using namespace std;
int n,queen[20][20],pl[20],ans;
int col[20],ll[40],rr[40];

void dfs(int x){
    if(x>n){
        if(ans++<3){
            for(int i=1;i<=n;i++)cout<<pl[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(!col[i]&&!ll[x+i]&&!rr[x-i+n]){
            col[i]=ll[x+i]=rr[x-i+n]=1;
            pl[x]=i;
            dfs(x+1);
            pl[x]=0;
            col[i]=ll[x+i]=rr[x-i+n]=0;
        }

    }
}

int main(){
    // freopen("1.txt","r",stdin);
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}

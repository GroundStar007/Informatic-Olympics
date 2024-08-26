#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+10;
int n,opt,x,root,idx;
struct Q{int p,s[2],v,size,cnt;}f[N];
void push_up(int x){

}
void rotate(int x){
    int y=f[x].p,z=f[y].p;
    int k=(f[y].s[1]==x);
    f[f[x].s[k^1]].p=y;
    f[y].s[k]=f[x].s[k^1];
    f[y].p=x;
    f[x].s[k^1]=y;
    f[z].s[f[z].s[1]==y]=x;
    f[x].p=z;
    push_up(x);
}
void splay(int x,int k){

}
void insert(int v){

}
void Delete(int x){

}
int ranks(int x){

}
int Get_Ranks(int x){

}
int pre(int x){

}
int suc(int x){

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>opt>>x;
        if(opt==1)insert(x);
        if(opt==2)Delete(x);
        if(opt==3)cout<<ranks(x)<<endl;
        if(opt==4)cout<<Get_Ranks(x)<<endl;
        if(opt==5)cout<<pre(x)<<endl;
        if(opt==6)cout<<suc(x)<<endl;
    }
    return 0;
}

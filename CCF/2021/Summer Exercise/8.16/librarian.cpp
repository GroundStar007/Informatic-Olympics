#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q,read[1009][2],book[1009],summ=0,minn=2e8,mi=1;
    // freopen("1.txt","r",stdin);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>book[i];
    for(int i=0;i<q;i++)cin>>read[i][0]>>read[i][1];
    for(int i=0;i<q;i++){
        minn=2e8,summ=0,mi=1;
        mi=pow(10,read[i][0]);
        for(int j=0;j<n;j++)
            if(book[j]%mi==read[i][1]){
                summ++;
                if(book[j]<minn)minn=book[j];
            }
        if(summ!=0)cout<<minn<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
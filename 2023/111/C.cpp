#include <iostream>
#include <cstdio>
using namespace std;
int n,summ,flag,price,timem,a[100009][2],ans,h;
bool flag1=false;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        flag1=false;
        cin>>flag>>price>>timem;
        if(flag==0){
            a[ans][0]=price;
            a[ans][1]=timem;
            summ+=price;
            ans++;
        }
        else if(flag==1){
            if(ans<=45)h=0;
            else h=ans-45;
            for(int j=h;j<ans;j++){
                if(a[j][0]>=price&&timem-a[j][1]<=45){
                    a[j][0]=a[j][1]=0;
                    flag1=true;
                    break;
                }
            }
            if(flag1==false)summ+=price;
        }
    }
    cout<<summ;
    return 0;
}

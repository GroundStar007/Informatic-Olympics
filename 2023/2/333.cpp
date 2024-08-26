#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 500010
using namespace std;
struct block{
    long long d, p;
}bs[maxn];
long long n, d, q, f[maxn], l, r, mid; //注意开long long
bool dp_check(long long g){
    memset(f, -127, sizeof(f)); 
    f[0] = 0;
    long long int lg = d - g, rg = d + g;
    if(lg <= 0) lg = 1;
    for(long long int i = 1; i <= n; i++){
        for(long long int j = i-1; j >= 0; j--){
            if(bs[i].d-bs[j].d >= lg && bs[i].d-bs[j].d <= rg) 
                f[i] = max(f[i], f[j] + bs[i].p);
            else if(bs[i].d-bs[j].d > rg) break; //优化1
        }
        if(f[i] >= q) return true; //优化2
    }
    return false;
}
int main(){
    scanf("%lld%lld%lld", &n, &d, &q);
    for(long long int i = 1; i <= n; i++){
        scanf("%lld%lld", &bs[i].d, &bs[i].p);
        // r = max(r, bs[i].d);
    }
    r = 1005;
    while(l < r){
        mid = (l + r) / 2;
        if(dp_check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}

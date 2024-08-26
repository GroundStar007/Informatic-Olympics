v//01背包
for (int i = 1; i <= N; i++) {    //对于第i个物品
    for (int v = 0; v <= V; v++) {    //枚举容积
        F[i][v] = F[i - 1][v];    //不选择第i件物品
        //如果容积足够且选择第i件物品更优
        if (v - C[i] >= 0 && F[i][v] < F[i - 1][v - C[i]] + W[i])   
            F[i][v] = F[i - 1][v - C[i]] + W[i];
    }
}

for(int v = 0; v <= V; ++ v)
    ans = max(ans, f[N][v]);



//01背包优化
void ZeroOnePack(int cost,int value) {  
    for(int i = v; i >= cost; i --)
        f[i] = max(f[i], f[i - cost] + value);
}

for(int i = 1; i <= n; ++ i) 
    ZeroOnePack(cost[i], value[i]);

ans = f[V];


for(int i = 1; i <= n; ++ i)
    for(int v = V; v >= c[i]; -- v)
        f[v] = max(f[v], f[v - c[i]] + w[i])

//完全背包
void CompletePack(int cost, int value) { 
    for(int i = cost; i <= v; i ++)
        f[i] = max(f[i], f[i - cost] + value);
}

ans = f[V];


//多重背包
void MultiPack(int cost ,int value, int amount) {
    if(v<=cost*amount) {
         CompletePack(cost,value);
         return;
    } else {
        int k=1;
        while(k<amount) {
            ZeroOnePack(k*cost,k*value);
            amount-=k;
            k*=2;
        }
        ZeroOnePack(amount*cost,amount*value);
    }
}
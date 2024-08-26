#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 510;
int l[N][N],r[N][N];
int high[N][N];
int n,m;
bool vis[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int qx[N * N], qy[N * N];
inline int read() {
	int w=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){w=w*10+c-'0';c=getchar();}
	return w*f;
}
inline void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dx[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (high[xx][yy] >= high[x][y]) continue;
        if (!vis[xx][yy]) dfs(xx, yy);
        l[x][y] = min(l[x][y], l[xx][yy]);
        r[x][y] = max(r[x][y], r[xx][yy]);
    }
}
int main() {
    n = read(), m = read();
    memset(vis, 0, sizeof(vis));
    memset(l, 0x3f, sizeof(l));
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= m; i++)
        l[n][i] = i, r[n][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            high[i][j] = read();
    for (int i = 1; i <= m; i++)
        if (!vis[1][i]) dfs(1, i);
    bool flag = false;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
        if (!vis[n][i]) {
            flag = true;
            cnt ++;
        }
    if (flag) {
        printf("0\n%d",cnt);
        return 0;
    }
    int left = 1;
    while (left <= m){
        int maxr = 0;
        for (int i = 1; i <= m; i++)
            if (l[1][i] <= left)
                maxr = max(maxr, r[1][i]);
        cnt++;
        left = maxr + 1;
    }
    printf("1\n%d",cnt);
}

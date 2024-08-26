#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <climits>
using namespace std;
inline int read() {
	int w=0,f=1;char c=getchar();
	while(c<'0'&&c<'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){w=w*10+c-'0';c=getchar();}
	return w*f;
}
typedef long long ll;
const int N = 1e5 + 10;
const int M = 3e5 + 10;
const long long Inf = LLONG_MAX / 2;
int n, m, fa[N], T;
int f[N][25]; // 倍增祖先
int dep[N];  // 最小生成树内点深
long long max_1[N][25];  // 最大值
long long max_2[N][25];  // 最小值
struct Node {
	int id, val;
};
vector<Node> G[N];
struct Edge{
	int u, v;
	long long val;
	bool operator < (const Edge a) const {
		return val < a.val;
	}
} E[M << 1];
inline int dsu_find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = dsu_find(fa[x]);
}
inline void merge(int x, int y) {
	x = dsu_find(x), y = dsu_find(y);
	if (x != y) fa[x] = y;
}
long long tot = 0;  // 最小生成树边权总和
inline void kruskal() {  // 最小生成树
	int cnt = 0;
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(E + 1, E + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = E[i].u;
		int v = E[i].v;
		long long val = E[i].val;
		if (dsu_find(u) != dsu_find(v)) {
			cnt ++;
			Node a;
			a.id = v, a.val = val; G[u].push_back(a);
			a.id = u; G[v].push_back(a);
			merge(u, v);
			tot += val;
		}
		if (cnt == n - 1) break;
	}
}
inline void dfs(int x, int father, long long w) {
	dep[x] = dep[father] + 1;
	f[x][0] = father;
	max_1[x][0] = w;	 // 最大值为边权
	max_2[x][0] = -Inf;  // 次小值
	for (int j = 1; j <= T; j ++) {  // 更新最大值以及次大值
		f[x][j] = f[f[x][j - 1]][j - 1];
		max_1[x][j] = max(max_1[x][j - 1], max_1[f[x][j - 1]][j - 1]);
		max_2[x][j] = max(max_2[x][j - 1], max_2[f[x][j - 1]][j - 1]);
		if (max_1[x][j - 1] == max_1[f[x][j - 1]][j - 1]) // 更新次小值
			max_2[x][j] = max(max_2[x][j - 1], max_2[f[x][j - 1]][j - 1]);
		if (max_1[x][j - 1] > max_1[f[x][j - 1]][j - 1])
			max_2[x][j] = max(max_1[f[x][j - 1]][j - 1], max_2[x][j - 1]);
		if (max_1[x][j - 1] < max_1[f[x][j - 1]][j - 1])
			max_2[x][j] = max(max_1[x][j - 1], max_2[f[x][j - 1]][j - 1]);
	}
	for (int i = 0; i < (int)G[x].size(); i++) {
		int to = G[x][i].id;
		long long val = G[x][i].val;
		if (to == father) continue;
		dfs(to, x, val);
	}
}
inline int LCA(int x, int y) {  // 倍增求LCA
	if (dep[x] < dep[y]) swap (x, y);
	for (int i = T; i >= 0; i -- )
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	if (x == y) return x;
	for (int i = T; i >= 0; i -- )
		if (f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}
inline long long QueryMax(int x, int lca, long long val) {
	long long ans = -Inf;
	// 在倍增跳到 lca 的过程中计算单条边权最大值
	for (int i = T; i >= 0; i--) {
		if (dep[f[x][i]] >= dep[lca]) {
			if (val != max_1[x][i]) // 与最大边权不等，则用最大边权更新
				ans = max(ans, max_1[x][i]);
			else
				ans = max(ans, max_2[x][i]);  // 否则用次大边权更新
			x = f[x][i];  // 跳上去
		}
	}
	return ans;
}
int main() {
	n = read(), m = read();
	T = log(n) / log(2) + 1;
	// 存图，先以边为单位存
	for (int i = 1, u, v, z; i <= m; i++) {
		u = read(), v = read(), z = read();
		if (u == v) continue;
		E[i].u = u, E[i].v = v, E[i].val = z;
	}
	// 求最小生成树并建图
	kruskal();
	// 从根节点搜，初始化节点信息
	int root;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i) {
			root = i;
			break;
		}
	max_2[root][0] = Inf;
	dep[root] = 1;
	dfs(root, 0, 0);
	// 枚举可加入的边
	bool vis[M];
	memset(vis, 0, sizeof vis);
	long long ans = Inf;
	for (int i = 1; i <= m; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		int lca = LCA(E[i].u, E[i].v);
		long long m1 = QueryMax(E[i].u, lca, E[i].val);
		long long m2 = QueryMax(E[i].v, lca, E[i].val);
		ans = min(ans, tot - max(m1, m2) + E[i].val * 1ll);
	}
	cout << ans;
	return 0;
}

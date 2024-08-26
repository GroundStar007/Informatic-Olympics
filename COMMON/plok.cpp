#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <cmath>
#define pci pair<char, int>
#define mkp make_pair
#define fir first
#define sec second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int t, L, w;
int MinErrDepth = -1, cnt; // 最小不可执行循环深度, 时间复杂度幂计数
char complexity[20], type, name;
string x, y;  // 起止
bool vis[30], flag;
stack<pci> s;
void FetchComplexity() {
    if (strlen(complexity) <= 4) w = 0;
    else sscanf(complexity, "O(n^%d)", &w);
}
void init() {
    memset(vis, 0, sizeof vis);
    MinErrDepth = -1, cnt = 0, w = 0;
    while (!s.empty()) s.pop();
    flag = false;
}
void F() {  // 新的循环体开始
    cin >> name >> x >> y; // 输入变量名以及起止
    // 判断变量名
    if (vis[name - 'a']) flag = true;   // 如果已经出现，则标记语法错误
    else vis[name - 'a'] = true;        // 未出现，标记出现
    // 当前变量名 + 当前循环深度 入栈
    s.push(mkp(name, (!s.empty() ? s.top().sec + 1 : 1)));
    // 循环起止复杂度判断
    if (x == "n" || y == "n") { // 有可能出现指数复杂度
        if (x != "n" && y == "n" && MinErrDepth == -1)  // 指数复杂度且可执行循环下
            cnt ++;         // 计数 ++
        else if (x == "n" && y != "n" && MinErrDepth == -1) // 不可执行且错误深度未更新
            MinErrDepth = s.top().sec, flag = true;
    }
    else if (x > y) {       // 不可能为指数复杂度 且 语法错误（此情况下语法正确不必考虑
        flag = true;        // 标记语法错误
        if (MinErrDepth == -1)
            MinErrDepth = s.top().sec;
        else
            MinErrDepth = min(MinErrDepth, s.top().sec);
    }
}
void E() { // 循环体结束
    if (MinErrDepth == s.top().sec) MinErrDepth = -1;
    vis[s.top().fir - 'a'] = false;
    if (!s.empty()) s.pop();
    return;
}
void Jduge() {
    if (flag == true || !s.empty()) cout << "ERR" << endl;
    else if (cnt != w) cout << "No" << endl;
    else cout << "Yes" << endl;
    return;
}
int main() {
    // freopen("1.txt", "r", stdin);
    cin >> t;
    int num = 0;
    while (t --) {
        // cout << "--------" << ++num << " ";
        init();
        cin >> L >> complexity;
        FetchComplexity();
        while (L --) {
            cin >> type;
            if (type == 'F') F();
            if (type == 'E') E();
        }
        Jduge();
        // cout << w <<" " << cnt << endl;
    }
    return 0;
}

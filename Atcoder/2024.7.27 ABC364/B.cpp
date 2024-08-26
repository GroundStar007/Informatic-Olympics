#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int h, w;
int sx, sy;
int main() {
    cin >> h >> w >> sx >> sy;
    sx--, sy--;
    vector<string> s(h);
    for (auto& x : s)
        cin >> x;
    string op;
    cin >> op;
    for (auto c : op) {
        int nx, ny;
        if (c == 'L') {
            nx = sx + dx[3];
            ny = sy + dy[3];
        } else if (c == 'R') {
            nx = sx + dx[1];
            ny = sy + dy[1];
        } else if (c == 'U') {
            nx = sx + dx[2];
            ny = sy + dy[2];
        } else {
            nx = sx + dx[0];
            ny = sy + dy[0];
        }
        if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#')
            continue;
        sx = nx;
        sy = ny;
    }
    cout << sx + 1 << " " << sy + 1 << '\n';
    return 0;
}
